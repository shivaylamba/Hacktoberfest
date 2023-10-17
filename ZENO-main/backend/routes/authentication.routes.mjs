import express from "express";

const router = express.Router()

router.use('/', (req, res, next)=>{

    // const flag = "accessToken" in req.cookies;
    // console.log(flag);
    // console.log(req.cookies.accessToken);

    if (("accessToken" in req.cookies) && req.cookies.accessToken)
        return next();
    else
        return res.send({Success : false})
})
export default router