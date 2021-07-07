var xhr = new XMLHttpRequest();
xhr.open("GET", "https://reqres.in/api/users");
xhr.send();
xhr.addEventListener("load", () => {
  if(xhr.status >= 200 && xhr.status <= 226) {
    console.log(xhr.responseText);
  }else{
    console.log("Cannot retrieve data from source");
  }
});
