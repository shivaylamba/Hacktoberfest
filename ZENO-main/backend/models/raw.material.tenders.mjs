import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Product : String,
     Owner : String,
     Retailer : String,
     Material : String,
     Capacity : Number,
     Price : Number,
     Status : String, // setup request // accepted request by manufacturer // raw material with distributor // raw material received
     IsActive : { type : Boolean, default : true},
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('rawmaterialtender', schema);

export default model;