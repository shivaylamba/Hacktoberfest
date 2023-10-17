// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;

contract DigiChambers{
    
    constructor() public payable{}
    //ethers receive and sent section
    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }


    // Secret Key for Certificate Creation
    string secKey = "P#r&a^t1109";
    string [] issuedCert;


    // issue a Certificate of origin
    function issueCeritificateofOrigin(string memory _UniqueString) public returns(string  memory){
        string memory certificateUnique = string(abi.encodePacked(_UniqueString, secKey));
        issuedCert.push(certificateUnique);
        return certificateUnique;
    }
    function lastCert() public view returns(string memory){
        return issuedCert[issuedCert.length - 1];
    }
    function memcmp(bytes memory a, bytes memory b) internal pure returns(bool){
        return (a.length == b.length) && (keccak256(a) == keccak256(b));
    }
    function strcmp(string memory a, string memory b) internal pure returns(bool){
        return memcmp(bytes(a), bytes(b));
    }


    // verfiy and audit the certificate of origin
    function verifyCeritificateofOrigin(string memory _UniqueString) public view returns(bool){
        bool flag = false;
        for (uint i = 0; i < issuedCert.length; i++)
            if (strcmp(issuedCert[i], _UniqueString))
                flag = true;
        
        return flag;        
    }
    
}