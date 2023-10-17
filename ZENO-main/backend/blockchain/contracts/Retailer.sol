// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
pragma experimental ABIEncoderV2;

contract Retailer{
    
    constructor() public payable{}
    //ethers receive and sent section
    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }


    // Product Creation and Retrieval
    
    struct Material{
        string material;
        int capacity;
        int price;
    }
    mapping(string => Material[]) product;

    function createProduct(string memory _product, string memory _material, int _capacity, int _price) public{
        Material memory m;
        m.material = _material;
        m.capacity = _capacity;
        m.price = _price;
        product[_product].push(m);
    }

    function getProduct(string memory _product) public view returns(Material[] memory){
        return product[_product];
    }



}