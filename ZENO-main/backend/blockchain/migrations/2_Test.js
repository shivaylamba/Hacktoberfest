const test = artifacts.require("test");

module.exports = function(deployer) {
  deployer.deploy(test);
};
