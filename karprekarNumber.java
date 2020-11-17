import java.util.*;
class Karprekar
{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int sq=n*n , digit=0;
    
    while(sq !=0)
    {
      digit++;
      sq/=10;
    }
    
    sq=n*n;
   
      int eq_parts = (int) Math.pow(10, digit/2); 
    
       int sum = sq/eq_parts + sq % eq_parts; 
        
        if(sum == n)
        System.out.println("Kaprekar Number");
        
        else
        System.out.println("Not kaprekar number");
   }
} 
