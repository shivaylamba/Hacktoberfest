const request = require('request');

// request('http://www.google.com', function (error, response, body) {
//   console.error('error:', error); // Print the error if one occurred
//   console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
//   console.log('body:', body); // Print the HTML for the Google homepage.
// });


request('https://samples.openweathermap.org/data/2.5/weather?q=London,uk&appid=b6907d289e10d714a6e88b30761fae22', function (error, response, body) {
  if(!error && response.statusCode==200){
  	var parseData =JSON.parse(body);
  	console.log('Weather at ', parseData["name"], ' is ', parseData.weather[0].description);
  	//console.log(parseData);
  } else {
  	  console.error('error:', error); // Print the error if one occurred
  }

});