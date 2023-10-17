// SPDX-License-Identifier: MIT
pragma solidity 0.5.0;
import "./Manufacturer.sol";

contract test {

    function() external payable{}

    function getAddress()  public view returns (address){
        return address(this);
    }

    function get() public pure returns (string memory) {
        return "Blockchain Connection succesful";
    }
}

// test.class_defaults.from = '0x535ec26742feD9Fe9Bd98D851F60B17e621ca68e'
