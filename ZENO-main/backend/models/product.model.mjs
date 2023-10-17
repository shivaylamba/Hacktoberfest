import mongoose from "mongoose";

const schema = new mongoose.Schema({
     Owner : String,
     Product: String,
     Cost : {type : Number, default : 0},
     Requirement : [{_material : String, _capacity : Number}],
     timestamp: { type: Date, default: Date.now}
});

const model = mongoose.model('product', schema);

export default model;