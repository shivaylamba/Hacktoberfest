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

// approve request
router.get('/approve-reject-request', async (req, res)=>{
    console.log(req.query)
    const Request = {
        ID : req.query._id,
        Status : req.query.Status,
        ops : req.query.ops
    };

    console.log(Request)
    if (Request.ops == "Accept"){
        await db.certificateRequest.findOne({_id : Request.ID,
             Status : "Request Raised for Certificate of Origin"})
             .then(async (result)=>{

            console.log(result)
            if (result == null)
                return;
            else{

                // update from blockchain digichambers
                await DigiChambers.issueCeritificateofOrigin(result.CertificateID, { from: process.env.defaultAccount })

                // final update on the database
                await db.certificateRequest.updateOne(result, {
                    $set: {
                        CertificateID : result.CertificateID + process.env.secKey,
                        Status : "Approved"
                    }
                });

                // after approval from DigiChambers, update will be take place on the database and  blockchain

                const contractInstance = await new web3.eth.Contract(manufacturer_ABI, result.Owner);
                // update on blockchain
                await contractInstance.methods.produce(result.Material, result.Capacity).send({ from: process.env.defaultAccount });

                // update on database
                await db.rawMaterial.create({
                            Owner :  result.Owner,
                            Material : result.Material,
                            // Price: result.Price,
                            CertificateID : result.CertificateID + process.env.secKey,
                            Capacity: parseInt(result.Capacity)
                });


                db.tracking.create({
                    CertificateID : result.CertificateID + process.env.secKey,
                    Operation : "Issuing-Certificate-of-Origin",
                    From : "DigiChambers",
                    To:  result.Owner,
                })
            }
        });


        
    }
    else{
        await db.certificateRequest.findOne({_id : Request.ID,
            Status : "Request Raised for Certificate of Origin"}).then(async (result)=>{
            
            if (result == null)
                return;
            else{
                // final update on the database
                await db.certificateRequest.updateOne(result, {
                    $set: {
                        Status : "Rejected",
                        IsActive : false
                    }
                });
            }
        })
    }

    
    

    res.redirect('/DigiChambers-Page')
})


router.get('/verify-cerificate', async(req, res)=>{
    const Request = {
        CertificateID : req.query.CertificateID,
        Status : req.query.Status
    };
    console.log(Request)
    await db.certificateRequest.findOne({ CertificateID : Request.CertificateID,
        Status : "Approved"}).then(async (result)=>{
        
        console.log(result)
        if (result == null)
            return res.send({status : false});
        else{
                const flag = await DigiChambers.verifyCeritificateofOrigin(Request.CertificateID)
                console.log(flag)
                if (flag == true)
                    return res.send({status : true});
                else
                    return res.send({status : false});
        }
    })
})

export default router;