// this is how we connect to blockchain
import Web3 from "web3";
import dotenv from "dotenv";
dotenv.config({ silent: process.env.NODE_ENV === 'production' });

// ganache address to web3
if (typeof web3 !== 'undefined') {
  var web3 = new Web3(web3.currentProvider)
} else {
  var web3 = new Web3(new Web3.providers.HttpProvider(process.env.ganache_server))
}

//setting accounts : default account => 0
const accounts = await web3.eth.getAccounts();
web3.eth.defaultAccount = accounts[0];

// setup to import json files
import contract from "@truffle/contract";
import { createRequire } from 'module';
const require = createRequire(import.meta.url);

// import smart contracts .json
const test_artifacts = require("./build/contracts/test.json");
const manufacturer_artifacts = require("./build/contracts/Manufacturer.json");
const distributor_artifacts = require("./build/contracts/Distributor.json");
const retailer_artifacts = require("./build/contracts/Retailer.json");
const customer_artifacts = require("./build/contracts/Customer.json");
const product_artifacts = require("./build/contracts/Product.json");
const transport_artifacts = require("./build/contracts/Transport.json")
const contracts_factory_artifacts = require("./build/contracts/Contracts_Factory.json");
const DigiChambers_Artifacts = require("./build/contracts/DigiChambers.json")


// Contracts Section :

// Test Contract
const Test = contract(test_artifacts)
Test.setProvider(web3.currentProvider)
const dummy = await Test.deployed();

// Manufacturer Contract
// const _manufacturer_artifacts = contract(manufacturer_artifacts);
// _manufacturer_artifacts.setProvider(web3.currentProvider)
// const manufacturer = await _manufacturer_artifacts.deployed();
const manufacturer_ABI = manufacturer_artifacts.abi;


// Distributor Contract
const distributor_ABI = distributor_artifacts.abi;

// Retailer Contract
const retailer_ABI = retailer_artifacts.abi;

// Customer Contract 
const customer_ABI = customer_artifacts.abi;

// Product Contract
const product_ABI = product_artifacts.abi;

// Transport Contract
const transport_ABI = transport_artifacts.abi;

// Contracts_Factory Contract
const _factory_artifacts = contract(contracts_factory_artifacts);
_factory_artifacts.setProvider(web3.currentProvider)
const factory = await _factory_artifacts.deployed();

// DigiChambers Contract
const _DigiChambers_Artifacts = contract(DigiChambers_Artifacts);
_DigiChambers_Artifacts.setProvider(web3.currentProvider)
const DigiChambers = await _DigiChambers_Artifacts.deployed();


export {
    web3,
    dummy,
    manufacturer_ABI,
    distributor_ABI,
    retailer_ABI,
    customer_ABI,
    product_ABI,
    transport_ABI,
    factory,
    DigiChambers
};

