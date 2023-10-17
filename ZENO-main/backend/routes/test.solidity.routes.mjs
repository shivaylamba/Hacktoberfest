import express from "express";
import dotenv from "dotenv";
import Contract from "web3-eth-contract";
import CircularJSON from "circular-json";

dotenv.config({ silent: process.env.NODE_ENV === 'production' });

import {  web3,
        manufacturer_ABI,
        factory }
          from "../blockchain/blockchain.conn.mjs";
const router = express.Router();

// router.get('/deploy-instances', async (req, res)=>{

//     await factory.createManufacturer({ from:  process.env.defaultAccount});
//     const index = await factory.get_manufacturer_SIZE({from : process.env.defaultAccount});
    
//     const all_manufacturer = await factory.allManufacturers({from : process.env.defaultAccount});
//     const contractAddress = all_manufacturer[parseInt(index) - 1];
//     const contractInstance = await new web3.eth.Contract(manufacturer_ABI, contractAddress);
//     console.log(contractInstance)
//     await web3.eth.sendTransaction({ to : contractAddress , from : process.env.defaultAccount, value : web3.utils.toWei('1', 'ether')});
//     console.log(all_manufacturer)
//     res.send(contractInstance);
// });



// router.get('/check-instances', async (req, res)=>{

 
//   const index = await factory.get_manufacturer_SIZE({from : process.env.defaultAccount});
//   const all_manufacturer = await factory.allManufacturers({from : process.env.defaultAccount});
//   const contractAddress = all_manufacturer[0];

//     var contractInstance  = await new web3.eth.Contract(manufacturer_ABI, contractAddress);

//     const balance = await web3.eth.getBalance(contractAddress)
//     let count = await contractInstance.methods.material().call();
//     console.log(balance);
//     console.log(count);
//     await contractInstance.methods.produce().send({from : process.env.defaultAccount})
//     count = await contractInstance.methods.material().call();
//     console.log(count);

//     res.send(contractInstance);
// })

router.get('/get-balance', async (req, res)=>{
  const balance = await web3.eth.getBalance(req.body.Account);
  res.send({Balance : balance});
});
router.get('/send-money', async (req, res)=>{
  await web3.eth.sendTransaction({from : req.body.sender , to : req.body.receiver , value : '1'});
  res.send({Success : true});
});

export default router;