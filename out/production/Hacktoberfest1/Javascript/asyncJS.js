//before
console.log("i was called before setTimeOut")
setTimeout(sayHi,2000)
function sayHi(){
    console.log("hi steve")
}
console.log("i was called after setTimeOut");
while(true){
    console.log("I am infinite")
}