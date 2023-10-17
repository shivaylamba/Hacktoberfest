const Retailer= artifacts.require("Retailer");

module.exports = function(deployer) {
  deployer.deploy(Retailer);
};
