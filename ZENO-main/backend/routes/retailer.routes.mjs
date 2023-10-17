// create a product
// place a diff request for each raw material and pay ether 

import express from "express";
import db from "../models/index.mjs"
import {
    web3,
    retailer_ABI,
    product_ABI,
    distributor_ABI,
    factory,
    transport_ABI
} from "../blockchain/blockchain.conn.mjs";

const router = express.Router();

router.post('/create-product', async (req, res) => {

    // no need to update the Product Contract with material data, as it is wastage of gas
    // .createProduct() not required

    const user = req.cookies.accessToken;
    // const contractInstance = await new web3.eth.Contract(retailer_ABI, user.ContractAddress);

    const product = {};
    product.Owner = user.ContractAddress;
    product.Product = req.body.Product;
    product.Price = req.body.Price;

    // update on blockchain
    product.Requirement = [];
    product.Requirement.push({ _material: req.body.material_1, _capacity: req.body.capacity_1, _price: req.body.price_1 });
    // await contractInstance.methods.createProduct(req.body.Product, req.body.material_1, req.body.capacity_1, req.body.price_1).send({ from: process.env.defaultAccount });

    if (req.body.material_2 != "") {
        product.Requirement.push({ _material: req.body.material_2, _capacity: req.body.capacity_2, _price: req.body.price_2 });
        // await contractInstance.methods.createProduct(req.body.Product, req.body.material_2, req.body.capacity_2, req.body.price_2).send({ from: process.env.defaultAccount });
    }
    if (req.body.material_3 != "") {
        product.Requirement.push({ _material: req.body.material_3, _capacity: req.body.capacity_3, _price: req.body.price_3 });
        // await contractInstance.methods.createProduct(req.body.Product, req.body.material_3, req.body.capacity_3, req.body.price_3).send({ from: process.env.defaultAccount });
    }

    // update on database
    await db.product.create(product);

    // res.send({ Success: true });
    res.redirect('/retailer-page');
});

// set Request for Raw Materials
router.post('/setup-raw-material-request', async (req, res) => {

    // html form only contains Product name here

    const user = req.cookies.accessToken; // accessing cookie

    // created a new contract for product
    // user.ContractAddress is owner
    await factory.createProduct(user.ContractAddress, { from: process.env.defaultAccount }); 
    const index = await factory.get_product_SIZE();
    const allProducts = await factory.allProducts();
    const ContractAddress = allProducts[index - 1];
    const productContract = await new web3.eth.Contract(product_ABI, ContractAddress); // product

    console.log(req.body.Product)
    console.log(user.ContractAddress)
    // access the product details from database and create a request for each one
    db.product.findOne({ Product: req.body.Product , Owner : user.ContractAddress}).then(async (result) => {

        console.log(result)
        // setup request // accepted request by manufacturer // raw material with distributor // raw material received

        if (result) {

            result.Requirement.forEach(async (element) => {
                await db.productRequest.create({
                    Product: ContractAddress,
                    Owner: user.ContractAddress,
                    Material: element._material,
                    Capacity: element._capacity,
                    Price: element._price,
                    currentOwner: user.ContractAddress,
                    Status: "Request-raised",
                })
                // console.log(user.ContractAddress)
                // console.log(user.eth_A)
                // console.log(ContractAddress)

                // sent money to the smart contract for material price
                await web3.eth.sendTransaction({ from: user.eth_Account, to: ContractAddress, value: element._price });

                await productContract.methods.setRequests(element._material).send({ from: process.env.defaultAccount });

            });

            // res.send({ Success: true })
            res.redirect('/retailer-page');
        }
        else
            res.redirect('/retailer-page');
            // return res.send({ Success: false })
    })

});


// approve the tender
router.post('/approve-raw-material-tender', async(req, res)=>{
    
    // product and rawmaterial
    console.log("req.body", req.body)

    // update on the database
    await db.rawMaterialTender.updateOne({Material : req.body.Material, Product : req.body.Product, Owner : req.body.Owner},
        {$set : { Status : "Approved" , IsActive : false}});

    // acceptance of request by manufacturer here
    const user = req.body.Owner; // accessing cookie



    await db.productRequest.findOne({ Product: req.body.Product, Material:req.body.Material, IsActive : true }).then(async (result) => {
        // console.log(result);
        console.log("result", result)
        if (result == null)
            return res.redirect('/retailer-Page');

    const productContract = await new web3.eth.Contract(product_ABI, result.Product);
         
        console.log("user", user)
        await db.rawMaterial.findOne({
            Owner : user,
            Material : result.Material,
            IsActive : true
        }).then(async (docs) => {
            await db.tracking.create({
                CertificateID : docs.CertificateID,
                Operation : "Approve-raw-material-tender",
                From : docs.Owner,
                To:  user,
            })
            console.log(docs)
            if (parseInt(docs.Capacity) >= parseInt(result.Capacity)) {
                
                // accept the request here : make transaction log on blockchain 
                // Update the Product Contract details
                await productContract.methods.acceptRequest(result.Material).send({ from: process.env.defaultAccount });

                // Update the productrequests collection
                await db.productRequest.updateOne(result, {$set : {Status : "Transport-request-raised", IsAcceptedbyManufacturer : true}});

                // Update the database entry for Request
                // if (parseInt(docs.Capacity) == parseInt(result.Capacity))
                //     await db.rawMaterial.updateOne(docs, { $set: {Capacity: 0 }});
                // else
                //     await db.rawMaterial.updateOne(docs, { $set: { Capacity: parseInt(docs.Capacity) - parseInt(result.Capacity)}});

                
                // Request for Transport  : make transport contract instance, send money, make db entry
                await factory.createTransport(user, {from : process.env.defaultAccount});
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
                    Manufacturer : user,
                    currentOwner : user,
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
                return res.redirect('/retailer-Page');
            }
            else {
                // res.send({ Success: false, Status: "Cannot fulfill the request" })
                console.log("ded")
                return res.redirect('/retailer-Page');
            }
        })

    })


});


router.post('/confirm-fulfillment-of-request', async (req, res) => {


    // to contract needs to fulfill at the same, html form will have 2 fields : product Address and transport address

    // accessing the cookie
    const user = req.cookies.accessToken;


    await db.transportRequest.findOne({ Transport: req.body.TransportAddress, IsActive: true }).then(async (result) => {

        if (result == null)
            return res.send({ Success: false });
        else {
            // update the Product contract
            const productContract = await new web3.eth.Contract(product_ABI, req.body.ProductAddress);
            await productContract.methods.fulfillRequest(result.Material).send({ from: process.env.defaultAccount });

            // update the Transport Contract
            const transportContract = await new web3.eth.Contract(transport_ABI, result.Transport);
            await transportContract.methods.fulfillRequest(result.Material).send({ from: process.env.defaultAccount });

            // update productrequest collection in database
            await db.productRequest.updateOne({ Product: req.body.ProductAddress }, {
                $set: {
                    currentOwner: user.ContractAddress,
                    Status: "Raw material received by retailer",
                    IsActive: false,
                    Isfulfilled: true
                }
            });

            // update transportRequest collection in database
            await db.transportRequest.updateOne({ Transport: req.body.TransportAddress }, {
                $set: {
                    currentOwner: user.ContractAddress,
                    Status: "Raw material received by retailer",
                    IsActive: false,
                    Isfulfilled: true
                }
            }).then(async(result)=>{
                  console.log("result", result)
                  // update the retailer stock in rawmaterials
                  // update on database
                  
                  await db.transportRequest.findOne({ Transport: req.body.TransportAddress}).then(async (ress)=>{
                    await db.rawMaterial.updateOne({Material: ress.Material, Owner : ress.Manufacturer}, {
                        $set: {
                            Owner: user.ContractAddress
                          }
                      });
  
                      await db.rawMaterial.findOne({ Material: ress.Material, Owner: user.ContractAddress }).then(async (docs) => {
                        await db.tracking.create({
                            CertificateID : docs.CertificateID,
                            Operation : "Confirm-delivery-of-Goods",
                            From : req.body.TransportAddress,
                            To:  user.ContractAddress,
                        })
              });
           })

                  
                  
            })

            
            
            // pay the distributor his money from smart contract
            // 
            res.redirect('/retailer-page');
        }
    })



});

// create a product on shelf for customers to buy


export default router;
