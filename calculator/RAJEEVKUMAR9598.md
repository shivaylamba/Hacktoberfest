<! DOCTYPE html>  
<html>  
    <head>    
    <title>  
         CREATE IN PERSONAL::: 
    </title>  
    <style>  
    html {  
  height: 100vh;  
  display: flex;  
  align-items: center; 
  border-radius: 5px 5px 5px 5px; 
  justify-content: center;  
  background-color: #b31dd1d7;
  shape-margin: 20px;  
  background-image: linear-gradient(315deg, #5517c7 0%, #dd383849 74%);  
  font-family: 'Courier New', Courier, monospace ;
  
} 
.title {  
margin:30px;  
padding: 5px 0;  
font-size: 40px;  
font-weight: bold;  
text-align: center;  
color: rgb(118, 211, 31);  
font-style: italic;
font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif;  
box-shadow: tomato;
border-radius: 5px;
box-shadow: red;
}  
input[type=button] {  
  width: 60px;  
  height: 60px;  
    
  padding: 15px 10px;  
  margin: 5px;  
  box-sizing: border-box;  
  background: #ecedef;  
  border: groove;  
  font-size: 30px; 
  font-style: italic; 
  line-height: 30px;  
  border-radius: 30%;  

  font-weight: bold;
  color: #be4a1c;  
  cursor: pointer;  
  box-shadow: 5px 5px 0px rgb(149, 22, 153);  

  display:inline-block;
  position: relative;
}  
input[type="text"] {  
  width: 270px;  
  height: 60px;  
  float: left;  
  padding: 0;  
  box-sizing: border-box;  
  border:papayawhip;  
  background: none;  
  display: inline-block;
  color: red;  
  text-align: right;  
  font-weight: 700;  
  font-size: 60px;  
  line-height: 60px;  
  margin: 0 25px;  
  
  position: relative;


  }  
.calculator {  
  
    border: radius 5px;
    

  
  background-image: url("iet.PNG");
}  
#display {  
  height: 40px;  
  text-align: right;  
  background-color: rgb(213, 223, 230) ;
  border: 3px solid white;  
  font-size: 18px;  
  left: 2px;  
  top: 2px;  
  color: rgb(24, 21, 226); 
  margin:10px; 
  border-radius:5px ;
  box-shadow: 4px 5px 5px indigo;
}  
div-2{  
    display: inline-flexbox;
    
}
hr{
    border: 2px dashed rgb(59, 18, 204);
    width:250px;
    margin-top: 5px;
}
input[type=button]:hover{
    cursor: pointer;
  transform: rotate(45deg);

  border-radius: 2px;
    </style>  
</head>  
<body>  
    <div class = "title"  align="center">  
        MADE BY RAJEEV GUPTA::::
    </div>  
    <form name="Calculator" class = "calculator" >  
      <div-2>
<table border="2" align="center" cellpadding="15" cellspacing="12" bgcolor="pink">  
<tr>  
<td>  
<input type="text" name="Input" Size="35" id="display" >  
<br>  
</td>  
</tr>  
<tr>  
<td>  

    <input type="button" name = "one" style="font-size:30px" value=" 1 " OnClick="Calculator.Input.value += '1'">  
<input type="button" name = "two" style = "font-size:30px" value=" 2 " OnCLick="Calculator.Input.value += '2'">  
<input type="button" name = "three" style="font-size:30px" value=" 3 " OnClick="Calculator.Input.value += '3'">  
<input type="button" name="add" class ="btnTop" style="font-size:30px" value=" + " OnClick="Calculator.Input.value += ' + '">  
<br>  
<input type="button" name = "four" style="font-size:30px" value=" 4 " OnClick="Calculator.Input.value += '4'">  
<input type="button" name = "five" style="font-size:30px" value=" 5 " OnCLick="Calculator.Input.value += '5'">  
<input type="button" name = "six" style="font-size:30px" value=" 6 " OnClick="Calculator.Input.value += '6'">  
<input type="button" name = "minus" style="font-size:30px" value=" - " OnClick="Calculator.Input.value += ' - '">  
<br>  
<input type="button" name = "seven" style="font-size:30px" value=" 7 " OnClick="Calculator.Input.value += '7'">  
<input type="button" name = "eight" style="font-size:30px" value=" 8 " OnCLick="Calculator.Input.value += '8'">  
<input type="button" name = "nine" style="font-size:30px" value=" 9 " OnClick="Calculator.Input.value += '9'">  
<input type="button" name = "mul" style="font-size:30px" value=" * "   
OnClick="Calculator.Input.value += ' * '">  
<br>  
<input type="button" name = "clear" style="font-size:30px" value=" c " OnClick="Calculator.Input.value = ''">  
<input type="button" name="zero" style="font-size:30px" value=" 0 " OnClick="Calculator.Input.value += '0'">  
<input type="button" name="DoIt" style="font-size:30px" value=" = " OnClick="Calculator.Input.value = eval(Calculator.Input.value)">  
<input type="button" name="div" style="font-size:30px" value=" / " OnClick="Calculator.Input.value += ' / '">  
<br>  
</td>  
  
</tr>  
</table>
</div-2>  
</form>  
</body>  
</html>  
