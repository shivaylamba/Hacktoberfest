import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Owner : String,
     CurrentPossesion : String,
     Material: String,
     Price : Number,
     Capacity : Number,
     CertificateID : { type : String, default : "Not allotted yet"},
     Status : String, // setup request // accepted request by distributor //  raw material received by retailer
     IsActive : { type : Boolean, default : true},
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('certificaterequest', schema);

export default model;