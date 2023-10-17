import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Transport : String,
     Product : String,
     Material : String,
     Capacity : Number,
     Manufacturer : String,
     Retailer : String,
     currentOwner : String,
     Status : String, // setup request // accepted request by distributor //  raw material received by retailer
     IsActive : { type : Boolean, default : true},
     IsAcceptedbyDistributor : { type : Boolean, default : false},
     Isfulfilled : { type : Boolean, default : false},
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('transportRequest', schema);

export default model;