const Contracts_Factory = artifacts.require("Contracts_Factory");

module.exports = function(deployer) {
  deployer.deploy(Contracts_Factory);
};
