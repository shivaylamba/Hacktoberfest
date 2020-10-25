fun fizzBuzzOf(input: Int) : String {
   var result : String = "";
   
   if(input % 3 == 0){
   	result += "Fizz"
   }
   
   if(input % 5 == 0){
   	result += "Buzz"
   }
   
   return if(!result.isNullOrEmpty()) result else input.toString()	
}
