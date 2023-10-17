import solidity_testing from "./test.solidity.routes.mjs";
import userView from "./user.view.routes.mjs"
import authentication from "./authentication.routes.mjs";
import RegisterRouter from "./user.register.routes.mjs";
import eth_manufacturer from "./manufacturer.routes.mjs";
import eth_retailer from "./retailer.routes.mjs";
import eth_distributor from "./distributor.routes.mjs"
import eth_digichambers from "./digiChambers.routes.mjs"


export {
    authentication,
    RegisterRouter,
    userView,
    solidity_testing,
    eth_manufacturer,
    eth_retailer,
    eth_distributor, 
    eth_digichambers
};