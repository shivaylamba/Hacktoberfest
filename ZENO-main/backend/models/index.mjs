import connectDB from "./connection.mjs";
import userModel from "./user.model.mjs"
import productModel from "./product.model.mjs";
import rawMaterialModel from "./raw.material.mjs";
import productRequestModel from "./product.request.model.mjs";
import transportRequestModel from "./transport.request.model.mjs";
import certificateRequestModel from "./certificate.request.model.mjs";
import rawMaterialTenderModel from "./raw.material.tenders.mjs";
import trackingModel from "./tracking.model.mjs"
// import transportTenderModel from "./transport.tenders.mjs"

const db = {};
db.connectDB = connectDB;
db.user = userModel;
db.product = productModel;
db.rawMaterial = rawMaterialModel;
db.productRequest = productRequestModel;
db.transportRequest = transportRequestModel;
db.certificateRequest = certificateRequestModel;
db.rawMaterialTender = rawMaterialTenderModel;
db.tracking = trackingModel;
// db.transportTender = transportTenderModel;


export default db;