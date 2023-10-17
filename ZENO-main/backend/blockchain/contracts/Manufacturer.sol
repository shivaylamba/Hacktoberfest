// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
pragma experimental ABIEncoderV2;

contract Manufacturer{

    constructor() public payable{}
    //ethers receive and sent section
    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }

    mapping(string=>int)material;
    int SIZE = 0;

    // General method to call : when manufacturer produces raw material
    function produce(string memory _material, int _capacity) public{
        material[_material] +=   _capacity;
        SIZE++;
    }

    // General method to call : to consume material
    function sell(string memory _material, int _capacity) public {
        material[_material] -= _capacity;
    }

    // General method to call : to check available stock
    function available(string memory _material) public view returns (int){
        return material[_material];
    }

      
} 

