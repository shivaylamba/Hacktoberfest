const express = require('express');

const app = express();

app.get("/", (req, res) =.{
  return res.json({message:"Server started"})
})


app.listen(3333, () => {
  console.log('📦 Back-end Started!')
})
