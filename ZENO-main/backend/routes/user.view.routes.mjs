import express from "express"
import db from "../models/index.mjs";

const router = express.Router()

// view pages for login and signup activities

router.get('/login-page', (req, res)=>{
    const data = {
        title : "Login",
        FormName : "Login",
        buttonName : "Login",
        api : "/register/login",
        method : "GET"
      }

    res.render("Login_Signup", {Data : data});
});

router.get('/signup-manufacturer', (req, res)=>{
    const data = {
        title : "Manufacturer Signup",
        FormName : "Manufacturer Signup",
        buttonName : "Create Account",
        api : "/register/create-manufacturer",
        method : "POST"
      }
      
    res.render("Login_Signup", {Data : data});
});

router.get('/signup-distributor', (req, res)=>{
    const data = {
        title : "Distributor Signup",
        FormName : "Distributor Signup",
        buttonName : "Create Account",
        api : "/register/create-distributor",
        method : "POST"
      }
      
    res.render("Login_Signup", {Data : data});
});

router.get('/signup-retailer', (req, res)=>{
    const data = {
        title : "Retailer Signup",
        FormName : "Retailer Signup",
        buttonName : "Create Account",
        api : "/register/create-retailer",
        method : "POST"
      }
      
    res.render("Login_Signup", {Data : data});
});

router.get('/signup-customer', (req, res)=>{
    const data = {
        title : "Customer Signup",
        FormName : "Customer Signup",
        buttonName : "Create Account",
        api : "/register/create-customer",
        method : "POST"
      }
      
    res.render("Login_Signup", {Data : data});
});

router.get('/manufacturer-Page', async (req, res) =>{


  // profile details
  // Update the stock
  // Pending requests, Approved Requests, Rejected Requests
  // Send the tender for product requets, after approval direct transport request will be send
  // approve the tenders of transfer requests
  
  const data = {
    Alert : "",
    Profile : req.cookies.accessToken,
    Requests : [],
    Approved : [],
    Rejected : [],
    ProductRequests : [],
    TransferTender : []
  };
  
  await db.certificateRequest.find({Owner : req.cookies.accessToken.ContractAddress}).then( async (result)=>{
    console.log("result", result)
    for (var i = 0; i < result.length; i++){
      if (result[i].Status == "Approved")
        data.Approved.push(result[i])
      else if (result[i].Status == "Rejected")
        data.Rejected.push(result[i])
      else
        data.Requests.push(result[i])
   }


    await db.productRequest.find({IsActive : true , Isfulfilled : false, IsAcceptedbyManufacturer : false}).then (async (result2)=>{
      data.ProductRequests = result2;
          // await db.transportTender.find({Owner : req.cookies.accessToken.ContractAddress, IsActive : true}).then(async(result3)=>{
          //   data.TransferTender = result3;
          // })
    });
  
  });
  
  console.log(data)
  res.render('MainPage_manu', {Data : data});
  // res.send({ true : true})
});

router.get('/retailer-Page', async (req, res) =>{

  const data = {
    Alert : "",
    Profile : req.cookies.accessToken, 
  };


  await db.transportRequest.find({retailer :req.cookies.accessToken.ContractAddress,  IsActive : true , IsAccepted : false, IsAcceptedbyDistributor: true}).then (async (result)=>{
    data.Requests = result;
    // console.log(data);
    await db.product.find({Owner : req.cookies.accessToken.ContractAddress}).then (async (docs)=>{
      // console.log(docs);
      data.Stock = docs;
      await db.productRequest.find({Owner : req.cookies.accessToken.ContractAddress, IsActive : true}).then (async (ress)=>{
        data.wRequests = ress;

        await db.rawMaterialTender.find({Retailer : req.cookies.accessToken.ContractAddress, IsActive : true}).then(async (res2)=>{
          data.tenders = res2;})

          await db.rawMaterial.find({Owner : req.cookies.accessToken.ContractAddress}).then( async (resultp)=>{
            data.Approved = resultp
           })

        res.render('MainPage_retail', {Data : data});
      })
    })
  });

});

router.get('/distributor-Page', async (req, res) =>{

  const data = {
    Alert : "",
    Profile : req.cookies.accessToken
  };

  await db.transportRequest.find({IsAcceptedbyDistributor : false,  IsActive : true , IsAccepted : false}).then (async (result)=>{
    data.Requests = result;
    res.render('MainPage_distr', {Data : data});
  });

});

router.get('/DigiChambers-Page', async(req, res)=>{
  const data = {
    Requests : [],
    Approved : [],
    Rejected : []
  };
  
  await db.certificateRequest.find().then( async (result)=>{
    for (var i = 0; i < result.length; i++){
      if (result[i].Status == "Approved")
        data.Approved.push(result[i])
      else if (result[i].Status == "Rejected")
        data.Rejected.push(result[i])
      else
        data.Requests.push(result[i])
    }

    console.log(data)
    res.render('MainPage_digiChambers', {Data : data});
  });

})

router.get('/asset-tracking-page', async(req, res)=>{
  const Data = {};
  console.log(req.query)
  if ("CertificateID" in req.query){
    await db.tracking.find({CertificateID : req.query.CertificateID}).then(async (result)=>{
      Data.asset = result;
    })
  }
  
  console.log(Data)
  res.render("Tracking", {Data : Data})
})

// first - entry into the website
router.get('/enter', (req, res)=>res.render("index_2options"));
router.get('/signup', (req, res)=>res.render("index_4options"));
router.get('/', (req, res)=>res.render("index"));

export default router 