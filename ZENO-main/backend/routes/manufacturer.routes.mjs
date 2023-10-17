import express from "express";
import {
    web3,
    factory,
    manufacturer_ABI,
    distributor_ABI,
    transport_ABI,
    product_ABI,
    DigiChambers
} from "../blockchain/blockchain.conn.mjs";

import db from "../models/index.mjs";

const router = express.Router();

router.post('/produce-material', async (req, res) => {

    const user = req.cookies.accessToken;
    // console.log(user)
    // const contractInstance = await new web3.eth.Contract(manufacturer_ABI, user.ContractAddress);

    // const contractAddress;
    const _material = req.body.Material;
    const _capacity = req.body.Capacity;

    // now only raise a request for Certificate of Origin
    await db.certificateRequest.create({
                Owner : user.ContractAddress,
                CurrentPossesion : user.ContractAddress,
                Material : _material,
                Capacity: parseInt(_capacity),
                CertificateID :  (Math.random() + 1).toString(36).substring(7),
                Status : "Request Raised for Certificate of Origin"
    });



    // after approval from DigiChambers, update will be take place on the database and  blockchain


    // // update on blockchain
    // await contractInstance.methods.produce(_material, _capacity).send({ from: process.env.defaultAccount });

    // // update on database
    // await db.rawMaterial.findOne({ Owner : user.ContractAddress, Material : req.body.Material}).then(async (result) => {

    //     if (result == null) {
    //         await db.rawMaterial.create({
    //             Owner : user.ContractAddress,
    //             Material : _material,
    //             Price: _price,
    //             Capacity: parseInt(_capacity)
    //         });
    //     }
    //     else {
    //         await db.rawMaterial.updateOne(result, {
    //             $set: {
    //                 Capacity: parseInt(result.Capacity) + parseInt(_capacity),
    //                 Price: parseInt(result.Price) + parseInt(_price)
    //             }
    //         });
    //     }
    // });

    // res.send({ Success: true });
    return res.redirect('/manufacturer-Page');

});

// accept the request for raw material, and create the request for transport
// receive the payment for raw mateial, and pay for transport

router.post('/accept-request', async (req, res) => {

    // html form only contains Request id

    const user = req.cookies.accessToken; // accessing cookie
    
    await db.productRequest.findOne({ Product: req.body.Product, Material:req.body.Material, IsActive : true }).then(async (result) => {
        console.log(result);
        if (result == null)
            return res.redirect('/manufacturer-Page');

        // const _capacity = await contractInstance.methods.available(result.Material).call();
        const productContract = await new web3.eth.Contract(product_ABI, result.Product);

        await db.rawMaterial.findOne({
            Owner : user.ContractAddress,
            Material : result.Material,
            IsActive : true
        }).then(async (docs) => {
            // console.log(docs)
            if (parseInt(docs.Capacity) >= parseInt(result.Capacity)) {
                
                // accept the request here : make transaction log on blockchain 
                // Update the Product Contract details
                await productContract.methods.acceptRequest(result.Material).send({ from: process.env.defaultAccount });

                // Update the productrequests collection
                await db.productRequest.updateOne(result, {$set : {Status : "Transport-request-raised", IsAcceptedbyManufacturer : true}});

                // Update the database entry for Request
                if (parseInt(docs.Capacity) == parseInt(result.Capacity))
                    await db.rawMaterial.updateOne(docs, { $set: {Capacity: 0 }});
                else
                    await db.rawMaterial.updateOne(docs, { $set: { Capacity: parseInt(docs.Capacity) - parseInt(result.Capacity)}});

                
                // Request for Transport  : make transport contract instance, send money, make db entry
                await factory.createTransport(user.ContractAddress, {from : process.env.defaultAccount});
                const alltransport = await factory.allTransports();
                const index = await factory.get_transport_SIZE();

                const TransportAddress = alltransport[index - 1];

                const Transport = await new web3.eth.Contract(transport_ABI, TransportAddress);

                // set-requests on blockchain & database
                await Transport.methods.setRequests(result.Material).send({ from: process.env.defaultAccount }); // blockchain
                
                await db.transportRequest.create({
                    Transport : TransportAddress,
                    Product : result.Product,
                    Material : result.Material,
                    Capacity : result.Capacity,
                    Retailer : result.Owner,
                    Manufacturer : user.ContractAddress,
                    currentOwner : user.ContractAddress,
                    Status : "Setup request"
                });

                //send money/ethers to the transport contract
                await web3.eth.sendTransaction({from : user.eth_Account, to : TransportAddress, value : process.env.transportCost});

                // receive money from product contract for respective raw material
               console.log(result.Price) 
               console.log(result.Product) 
               console.log(user.eth_Account) 
            //    await web3.eth.sendTransaction({from : result.Product, to : user.eth_Account,  value :result.Price});
                console.log("good")
                // res.send({Success : true})
                return res.redirect('/manufacturer-Page');
            }
            else {
                // res.send({ Success: false, Status: "Cannot fulfill the request" })
                console.log("ded")
                return res.redirect('/manufacturer-Page');
            }
        })

    })
    // return res.redirect('/manufacturer-Page');

})


// send tenders for particular product raw material requests
router.post('/send-raw-material-tender', async (req, res)=>{

    // after approval
    // update on blockchain

    console.log(req.body)

    // update on database
    await db.rawMaterialTender.create({
        Owner : req.cookies.accessToken.ContractAddress,
        Product : req.body.Product,
        Retailer : req.body.Retailer,
        Material : req.body.Material,
        Capacity : req.body.Capacity,
        Price :  req.body.Price,
        Status : "Send Proposal for raw material request.",
    })

    await db.rawMaterial.findOne({Owner : req.cookies.accessToken.ContractAddress, Material : req.body.Material}).then(async (docs)=>{
        await db.tracking.create({
            CertificateID : docs.CertificateID,
            Operation : "Sent-Proposal-for-raw-material-sell",
            From : req.cookies.accessToken.ContractAddress,
            To: req.body.Retailer,
        })
    })


    res.redirect('/manufacturer-page');


})
export default router;