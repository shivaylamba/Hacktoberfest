//Promise in JS example

var promise = new Promise(function(resolve, reject) { 
    resolve('Promise'); 
}) 
  
promise 
    .then(function(successMessage) { 
       //success 
        console.log(successMessage); 
    }, function(errorMessage) { 
        console.log(errorMessage); 
    }) 
