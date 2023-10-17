import express from "express";
import db from "../models/index.mjs";
import {
    web3, transport_ABI
} from "../blockchain/blockchain.conn.mjs";
const router = express.Router();

router.post('/accept-request', async (req, res) => {

    // html form only with single field Transport address
    const user = req.cookies.accessToken;
    
    
    await db.transportRequest.findOne({ Transport: req.body.TransportAddress, IsActive : true }).then(async (result) => {
        
        await db.rawMaterial.findOne({Owner : result.Manufacturer, Material : result.Material}).then(async (docs)=>{
            await db.tracking.create({
                CertificateID : docs.CertificateID,
                Operation : "transfer-of-assets-via-Distributor",
                From : result.Manufacturer,
                To:  user.ContractAddress,
            })
        })
        
        console.log(result)
        if (result == null)
            return res.send({Success : false });
        const transportContract = await new web3.eth.Contract(transport_ABI, result.Transport);

        // update on blockchain : transport contract, acceptRequest
        await transportContract.methods.acceptRequest(result.Material).send({from : process.env.defaultAccount});

        // update on database : chnage currentOwner, status
        await db.transportRequest.updateOne(result , {$set : {currentOwner : user.ContractAddress, Status : "Material is with Distributor", IsAcceptedbyDistributor : true}});

        // accept money from transport contract
        const allBalance = await web3.eth.getBalance(result.Transport)
        console.log(allBalance)
        // await web3.eth.sendTransaction({from : result.Transport, to : user.ContractAddress, value : allBalance})
    
    })  

    // res.send({Success : true })
    res.redirect('/distributor-Page');

})

export default router;