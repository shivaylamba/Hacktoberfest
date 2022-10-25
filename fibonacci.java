import java.util.*;
class fibonacci
{
public static void main(String args[])
{
 int a,b,c,n;a=0;b=1;c=0;n=3;
 System.out.println("The Fiboncci series is ");
 System.out.println(a);
 System.out.println(b);
 do
   {
    c=a+b;
    System.out.println(c);
    a=b;
    b=c;
    n=n+1;
}
while(n<=10);
}
}
 
 

      
      
      
