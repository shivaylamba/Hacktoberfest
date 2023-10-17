import mongoose from "mongoose";

const schema = new mongoose.Schema({
     CertificateID : String,
     Operation : String,
     From : String,
     To:  String,
     Access : {type : String, default : "ALL"},
     IsActive : { type : Boolean, default : true},
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('trackingmodel', schema);

export default model;