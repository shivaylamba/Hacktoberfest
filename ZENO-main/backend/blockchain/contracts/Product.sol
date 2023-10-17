// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
// pragma experimental ABIEncoderV2;

contract Product{

    string Retailer;

    constructor(string memory _owner) public payable{
       Retailer =  _owner ;
    }
    //ethers receive and sent section
    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }

    function getRetailer() public view returns (string memory){
        return Retailer;
    }


    // basic stages in product
    uint public index = 0;
    string[] public stages = [
        "Ideation Stage",
        "Requested for Raw Materials, In Progress",
        "All Raw Materials Requests fulfilled",
        "All Raw Materials are with DIstributor",
        "All Raw Materials processing to make product",
        "Product is Ready",
        "Product is bought by customer"
    ];

    function incrementStage() public {
        index++;
    }

    function getProductStage() public view returns(string memory){
        return stages[index];
    }

    

    // Applications
    
    string[] Materials;
    uint material_SIZE = 0;

    mapping(string => bool) requestStatus; // is it with retailer or not?
    mapping(string => bool) transportStatus; // is it with distributor or not

    function setRequests(string memory _material) public {
        requestStatus[_material] = false;
        transportStatus[_material] = false;
        material_SIZE++;
    }

    function acceptRequest(string memory _material) public {
        transportStatus[_material] = true;
    }

    function fulfillRequest(string memory _material) public {
         requestStatus[_material] = true;
    }

    function checkallRequests() public view returns(bool){
        bool flag = true;
        for (uint i = 0; i < material_SIZE; i++)
            if (requestStatus[Materials[i]] == false) // string comparison can also be done here
                flag = false;

        return flag;
    }



}