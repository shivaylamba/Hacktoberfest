const Distributor= artifacts.require("Distributor");

module.exports = function(deployer) {
  deployer.deploy(Distributor);
};
