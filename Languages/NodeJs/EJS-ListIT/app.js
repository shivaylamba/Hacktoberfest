var express = require("express");
var app = express();
var bodyParser =require("body-parser");
var list = ["Read books", "Code", "Workout"];

app.use(bodyParser.urlencoded({extended: true})); // adding body-parser
app.use(express.static("public")); // to serve public directory for express
app.set("view engine", "ejs");  // extention not needed if this line is active

app.get("/", function(req, res){
	//console.log('Hi');
	res.send("goto localhost:3000/listit ");
});

app.get("/listit", function(req, res){
	res.render("listit", { list: list });
});

app.post("/additem", function(req, res){
	var newitem = req.body.newitem;
	list.push(newitem);
	res.redirect("/listit");
	//.log(req.body.newitem);
	//res.send("Added !");
});


app.get("*", function(req, res){
	res.send("ERROR 404 PAGE NOT FOUND! GOOD BYE!");
});

app.listen(3000, function(){
	console.log('Server Started ...');
});