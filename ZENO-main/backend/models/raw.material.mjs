import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Owner : String,
     Material: String,
     Capacity : Number,
     CertificateID : String,
     IsActive : {type : Boolean, default : true},
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('rawmaterial', schema);

export default model;