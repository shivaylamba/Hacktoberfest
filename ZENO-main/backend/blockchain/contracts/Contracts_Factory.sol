// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
pragma experimental ABIEncoderV2;

import "./Manufacturer.sol";
import "./Distributor.sol";
import "./Retailer.sol";
import "./Customer.sol";
import "./Product.sol";
import "./Transport.sol";

contract Contracts_Factory {

    // Common Section
    uint256 SIZE = 10;
    uint index = 0;
    string[] accounts = [
        "0x535ec26742feD9Fe9Bd98D851F60B17e621ca68e",
        "0x71219f7633948D72B6ED5c50Abdef47714310aDb",
        "0x008AE1ca67F69C743D8Ff4e051D6b5e7aC7EE90B",
        "0xc68483F14a9e608f6c4f28b1354621d673E532b3",
        "0xd23752B4Cb567D914ea99Cf7E9138e1a6652f4AA",
        "0xFAC89d080476c67853e2D20cDf47BD9C36177616",
        "0xC085446132434a1584793015F3BcC569360f6DDf",
        "0xc0B03B26E74a7B6048cE4677073E2Aa3E64FD375",
        "0x149BA351e0Fb4368E3308841433Bb31CfA071758",
        "0x2cfd4FC4Ae8BA69a8E3CA3e514246F2B2f69d977"
    ];

    function getEthAccount() public view returns (string[] memory) {
        return accounts;
    }
    function getIndex() public view returns(uint){
        return index;
    }
    function incrementIndex() public {
       index++;
    }

    // Manufacturer Section
    int256 _manufacturer_SIZE = 0;
    Manufacturer[] _manufacturers;

    function createManufacturer() public {
        Manufacturer newManufacturer = new Manufacturer();
        _manufacturers.push(newManufacturer);
        _manufacturer_SIZE++;
    }

    function allManufacturers() public view returns (Manufacturer[] memory) {
        return _manufacturers;
    }

    function get_manufacturer_SIZE() public view returns (int256) {
        return _manufacturer_SIZE;
    }


    // Distributor Section
    int256 _distributor_SIZE = 0;
    Distributor[] _distributors;

    function createDistributor() public {
        Distributor newdistributor = new Distributor();
        _distributors.push(newdistributor);
        _distributor_SIZE++;
    }

    function allDistributors() public view returns (Distributor[] memory) {
        return _distributors;
    }

    function get_distributor_SIZE() public view returns (int256) {
        return _distributor_SIZE;
    }


    // Retailer Section
    int256 _retailer_SIZE = 0;
    Retailer[] _retailers;

    function createRetailer() public {
        Retailer newRetailer = new Retailer();
        _retailers.push(newRetailer);
        _retailer_SIZE++;
    }

    function allRetailers() public view returns (Retailer[] memory) {
        return _retailers;
    }

    function get_retailer_SIZE() public view returns (int256) {
        return _retailer_SIZE;
    }

    // Customer Section
    int256 _customer_SIZE = 0;
    Customer[] _customers;

    function createCustomer() public {
        Customer newManufacturer = new Customer();
        _customers.push(newManufacturer);
        _customer_SIZE++;
    }

    function allCustomers() public view returns (Customer[] memory) {
        return _customers;
    }

    function get_customer_SIZE() public view returns (int256) {
        return _customer_SIZE;
    }


    // Product Section
    int256 _product_SIZE = 0;
    Product[] _products;

    function createProduct(string memory _owner) public {
        Product newProduct = new Product(_owner);
        _products.push(newProduct);
        _product_SIZE++;
    }

    function allProducts() public view returns(Product[] memory){
        return _products;
    }

    function get_product_SIZE() public view returns (int256){
        return _product_SIZE;
    }

    // Transport Section
    int256 _transport_SIZE = 0;
    Transport[] _transports;

    function createTransport(string memory _owner) public {
        Transport newTransport = new Transport(_owner);
        _transports.push( newTransport);
        _transport_SIZE++;
    }

    function allTransports() public view returns(Transport[] memory){
        return _transports;
    }

    function get_transport_SIZE() public view returns (int256){
        return _transport_SIZE;
    }

}
