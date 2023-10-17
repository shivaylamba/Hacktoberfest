// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
// pragma experimental ABIEncoderV2;

contract Transport{

    string Distributor;

    constructor(string memory _owner) public payable{
       Distributor =  _owner ;
    }
    //ethers receive and sent section
    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }

    function getDistributor() public view returns (string memory){
        return Distributor;
    }


    // applications
    mapping(string => bool) importStatus; // is it with distributor or not
    mapping(string => bool) exportStatus; // is it with distributor or not
    uint material_SIZE = 0;

    function setRequests(string memory _material) public {
        importStatus[_material] = false;
        exportStatus[_material] = false;
        material_SIZE++;
    }

    function acceptRequest(string memory _material) public {
        importStatus[_material] = true;
    }

    function fulfillRequest(string memory _material) public {
         exportStatus[_material] = true;
    }

}