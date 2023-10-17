import express from "express";
import db from "../models/index.mjs";

import {
        web3,
        factory,
} from "../blockchain/blockchain.conn.mjs"

const router = express.Router();

// Create a new instance of smart contract , for each type of user


// Creating a new Manfacturer
router.post('/create-manufacturer', async (req, res)=>{
    console.log(req.body)

    const user = {};
    user.Email = req.body.Email;
    user.Password = req.body.Password;
    user.Role = "Manufacturer";
    user.IsActive = true;
    
    await factory.createManufacturer({ from:  process.env.defaultAccount});
    const index = await factory.get_manufacturer_SIZE({from : process.env.defaultAccount});
    
    const all_manufacturer = await factory.allManufacturers({from : process.env.defaultAccount});
    const contractAddress = all_manufacturer[parseInt(index) - 1];
    
    const Accounts = await factory.getEthAccount();
    const E_index = await factory.getIndex();
    await factory.incrementIndex({from : process.env.defaultAccount});
    
    user.ContractAddress = contractAddress;
    user.eth_Account = Accounts[E_index];

    // final operation
    db.user.create(user);

    // res.send(user); api result

    
      res.redirect("/login-page");

})

// Creatinfg a new Distributor
router.post('/create-distributor', async (req, res)=>{
    const user = {};
    user.Email = req.body.Email;
    user.Password = req.body.Password;
    user.Role = "Distributor";
    user.IsActive = true;
    
    await factory.createDistributor({ from:  process.env.defaultAccount});
    const index = await factory.get_distributor_SIZE();
    
    const all_distributor = await factory.allDistributors();
    const contractAddress = all_distributor[parseInt(index) - 1];
    
    const Accounts = await factory.getEthAccount();
    const E_index = await factory.getIndex();
    await factory.incrementIndex({from : process.env.defaultAccount});
    
    user.ContractAddress = contractAddress;
    user.eth_Account = Accounts[E_index];

    // final operation
    db.user.create(user);
    // res.send(user);
    res.redirect("/login-page");
})

router.post('/create-retailer', async (req, res)=>{
    const user = {};
    user.Email = req.body.Email;
    user.Password = req.body.Password;
    user.Role = "Retailer";
    user.IsActive = true;
    
    await factory.createRetailer({ from:  process.env.defaultAccount});
    const index = await factory.get_retailer_SIZE();
    
    const all_retailer = await factory.allRetailers();
    const contractAddress = all_retailer[parseInt(index) - 1];
    
    const Accounts = await factory.getEthAccount();
    const E_index = await factory.getIndex();
    await factory.incrementIndex({from : process.env.defaultAccount});
    
    user.ContractAddress = contractAddress;
    user.eth_Account = Accounts[E_index];

    // final operation
    db.user.create(user);
    // res.send(user);
    res.redirect("/login-page");
})

router.post('/create-customer', async (req, res)=>{
    const user = {};
    user.Email = req.body.Email;
    user.Password = req.body.Password;
    user.Role = "Customer";
    user.IsActive = true;
    
    await factory.createCustomer({ from:  process.env.defaultAccount});
    const index = await factory.get_customer_SIZE();
    
    const all_customer = await factory.allCustomers();
    const contractAddress = all_customer[parseInt(index) - 1];
    
    const Accounts = await factory.getEthAccount();
    const E_index = await factory.getIndex();
    await factory.incrementIndex({from : process.env.defaultAccount});
    // console.log(Accounts)
    // console.log(E_index)
    user.ContractAddress = contractAddress;
    user.eth_Account = Accounts[E_index];

    // final operation
    db.user.create(user);
    // res.send(user);
    res.redirect("/login-page");
})

router.get('/login', async (req, res)=>{
    const User = {};
    User.Email = req.query.Email;
    User.Password = req.query.Password;
    User.IsActive = true;
    // console.log(req.query)
    console.log(User)

    db.user.findOne(User).then(result=>{

        // console.log(result);
    
        if (result == null)
            return res.send({Success : false});
        else{
            res.cookie('accessToken', result);
            // return res.send({Success : req.cookies.accessToken});
            // res.redirect('/register/test-cookies')

            // redirect to the respective page according to the role
            if (result.Role == "Manufacturer"){
                return res.redirect('/manufacturer-Page');
            }
            else if (result.Role == "Distributor"){
                return res.redirect('/distributor-Page');
            }
            else if (result.Role == "Retailer"){
                return res.redirect('/retailer-Page');
            }
            else if (result.Role == "Customer"){
                
            }
            else if (result.Role == "DigiChambers"){
                return res.redirect('/DigiChambers-Page');
            }
        }
    });
})

// router.get('/test-cookies', (req, res)=>{
//     console.log("Here")
//     const user = req.cookies.accessToken;
//     // console.log(user)
//     res.send(user);
// })

export default router;