public class Swapping {

    public static void main(String[] args){

        int a = 10;
        int b = 30;

        a = a^b; // a now becomes 20 
        b = a^b;
        a = a^b; 

        System.out.println("a is:"+a);
        System.out.println("b is:"+b);
    }
}

// Proving how XOR works in this scenario 
/* 
 // a = 10 = 01010
 // b = 30 = 11110 
//Bit Representation      
//     01010  -> a
       11110  -> b 
       --------
       10100  -> c // same bits are 0, different bits are 1

       // lets say c = 10100 and b is given 11110 then
       // determining a involves these steps ->
       // 1. if bits of c is 1 and corresponding bit of b is 1 then bit of a must have been 0
       // 2. if bits of c is 1 and corresponding bit of b is 0 then bit of a must have been 1
       // 3. if bits of c is 0 and corresponding bit of b is 1 then bit of a must have been 1
       // 4. if bits of c is 0 and corresponding bit of b is 0 then bit of a must have been 0

       if we create a table for this we get
         b  |  c  |  a
        -------------------
         0  |  0  |  0  
         0  |  1  |  1     
         1  |  0  |  1
         1  |  1  |  0
        -------------------
       // this is exactly the same as the truth table of XOR gate
       // Basically I have info regarding a if I have b and a^b

       //if a^b = c then b^c = a and a^c = b 
       //this is because the logic to determine a from c and b is bitwise identical as the logic to determine c = a^b 
       
       
       */