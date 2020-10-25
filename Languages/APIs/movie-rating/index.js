var express = require("express");
var app = express();
var request = require("request");

app.get("/results", function(req, res){
	request('http://www.omdbapi.com/?s=california', function (error, response, body) {
	  if(!error && response.statusCode==200){
	  	var results =JSON.parse(body);
	  	console.log(results["Search"][0]["Title"]);
	  } else {
	  	  console.error('error:', error); // Print the error if one occurred
	  }
	});
});

app.get("*", function(req, res){
	res.send("ERROR 404 PAGE NOT FOUND! GOOD BYE!");
});

app.listen(3000, function(){
	console.log('Server Started ...');
});