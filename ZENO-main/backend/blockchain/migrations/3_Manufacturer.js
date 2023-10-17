const Manufacturer = artifacts.require("Manufacturer");

module.exports = function(deployer) {
  deployer.deploy(Manufacturer);
};
