const purchasePrice = document.getElementById('input-purchase');
const quantity  =document.getElementById('input-quantity');
const currentPrice = document.getElementById('input-current');
const searchResult = document.querySelector('#search-results');
const date = document.getElementById("date");
const lastUpdatedDate = document.getElementById("last-updated-date");
const btnResult = document.getElementById("btn-result");
const messageSmallOne = document.getElementById("one-small");
const messageSmallTwo = document.getElementById("two-small");
const btnCalculate = document.getElementById("btn-final");
const message = document.getElementById("message");
const main = document.querySelector('main');

// const BASE_URL = "https://www.alphavantage.co/query?";
// const API_KEY  = "&apikey=MAXZSUALDM00MSPN";

const keywordSearch = document.getElementById('search');

// currentPrice.addEventListener('click',()=>{
//     let purchasePriceValue = purchasePrice.value;
//     let quantityValue = quantity.value;
//     let currentPriceValue = currentPrice.value;
//     purchasePriceValue



// })

keywordSearch.addEventListener('keypress',(event)=>{

      if(event.key==="Enter"){
  
    console.log(keywordSearch.value);
    getSearchData(keywordSearch.value);
   
    }
 console.log(date.value);

})

btnResult.addEventListener("click",()=>{
  if( keywordSearch.value && date.value && keywordSearch.value.includes(',') ){
 
      const keywordArr = keywordSearch.value.split(',');
      const symbol =keywordArr[1].trim(); // trim removes whitespace 

       getTimeSeriesData(symbol);
        messageSmallTwo.innerText="loading"
      
    
  }else{
    messageSmallTwo.innerText="Make sure you have properly filled the required inputs";
  }
})
//working on search end point 
function getSearchData(keyword){
    var requestOptions = {
        method: 'GET',
        redirect: 'follow'
      };
     
      
      fetch(`https://www.alphavantage.co/query?function=SYMBOL_SEARCH&keywords=${keyword}&apikey=MAXZSUALDM00MSPN`, requestOptions)
        .then(response => response.json())
        .then(result =>{ getUserFriendlyData(result) 
        console.log(result)})
        .catch(error => console.log(error));
        
}



function getUserFriendlyData(result){
 console.log(result["bestMatches"].length)
if(result["bestMatches"].length!==0 || keywordSearch.value.includes(',')){
  

for ( let i =0;i<result["bestMatches"].length;i++){
  const options = document.createElement('option');
//   const atr  = document.createAttribute('value');
//   atr.value= 
  options.setAttribute("value",`${result["bestMatches"][i]["2. name"]}, ${result["bestMatches"][i]["1. symbol"]}`);
  searchResult.appendChild(options);
setTimeout(()=>{
  searchResult.removeChild(options);
},10000)
    
messageSmallOne.innerText="";
}
}else {
messageSmallOne.innerText="No Stocks Found. Please Check for any spelling mistakes."; // To be modified 
}

}
// date.addEventListener("click",()=>{ })

function getTimeSeriesData(symbol ){
  console.log(typeof(symbol));
  var requestOptionsTwo = {
    method: 'GET',
    redirect: 'follow'
  };
  fetch(decodeURIComponent(`https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol=${symbol}&outputsize=full&apikey=MAXZSUALDM00MSPN`),requestOptionsTwo)
        .then(response =>{ 
          
        return response.json();
        

      })
        .then((data) =>{
         
            if(data["Note"]){
          alert("You have exhausted all your  searches, kindly wait for a minute to use our services again");
            }
          dateValue = date.value
          displayStockPriceOnSpecifiedDate(data,dateValue)
        
        })
       
        .catch(error => console.log('error', error));

}



function displayStockPriceOnSpecifiedDate(timeDate, date){
  //purchasePrice.value="loading..."; // not working 
  lastUpdatedDate.innerText=timeDate["Meta Data"]["3. Last Refreshed"];
 try{
  purchasePrice.value= timeDate["Time Series (Daily)"][date]["5. adjusted close"]
  // adjusted close price of the stock in specified date 
  currentPrice.value =timeDate["Time Series (Daily)"][timeDate["Meta Data"]["3. Last Refreshed"]]["5. adjusted close"]
 console.log(typeof(purchasePrice.value))
messageSmallTwo.innerText="";
  }catch{
    messageSmallTwo.innerText="Enter a valid date"
    // currentPrice.value="Enter a valid date"
  }
  
  

}



btnCalculate.addEventListener("click",()=>{
const  purchasePriceValue = Number(purchasePrice.value);
const currentPriceValue = Number( currentPrice.value);
const quantityValue = Number( quantity.value);
const absolute = purchasePriceValue*quantityValue -currentPriceValue*quantityValue;
const percentage=(( currentPriceValue - purchasePriceValue) /purchasePriceValue )*100;
if(quantityValue>0 && purchasePriceValue>0 && quantityValue && purchasePriceValue && currentPriceValue){
  main.style.background="black";
  main.style.color="white";
 if(currentPriceValue<purchasePriceValue){
   if(Math.abs(percentage)>50){
   main.style.backgroundImage="linear-gradient(red,black)"
   main.style.color="white";
   }
   message.innerHTML=`You total loss is  ${absolute.toFixed(2)} and you lost ${Math.abs(percentage).toFixed(2) } percent  📉`
   
// console.log(absolute)
// console.log(Math.abs(percentage),"per-")
 } else{
  message.innerHTML=`You total profit is  ${Math.abs(absolute).toFixed(2)}  and you gained ${(percentage.toFixed(2))} percent 💹`
  if(percentage>50){
  main.style.backgroundImage="linear-gradient(green,black)"
  main.style.color="white";
  }
 }



}
else{
  message.innerHTML=`Enter all the required inputs`
}
}

)



// you need to manipulate the DOM and add the  stock options to it 
//you still need to do it 
// displaying the  data  in DOM 
//adding click event listener to the data 


//figuring out  how to reset datalist 



//data symbol to price endpoint 
//  spliting the input 
//46

//white space in url 

// solve the getStockPriceOnSpecifiedDate

//input the price to the price value 

//last updated price to be added


//final calculations