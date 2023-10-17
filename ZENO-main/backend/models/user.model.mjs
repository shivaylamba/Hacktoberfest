import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Email : String,
     Password : String,
     Role : String,
     ContractAddress : String,
     eth_Account : String,
     IsActive : Boolean,
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('user', schema);

export default model;