import mongoose from "mongoose";
import dotenv from "dotenv"
dotenv.config({ silent: process.env.NODE_ENV === 'production' });

const URI = `mongodb+srv://Prathamesh-Pawar:${process.env.Password}@cluster0.mnv2j.mongodb.net/myFirstDatabase?retryWrites=true&w=majority`;

const connectDB = async()=>{mongoose.connect(URI, { 
            useUnifiedTopology : true,
            useNewUrlParser : true
      })
    .then(() => console.log('MongoDB cluster connected...'))
    .catch(err => console.log(err))
};

export default connectDB;