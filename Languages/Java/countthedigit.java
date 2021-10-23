import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

class Main
{
  
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the number :");
		int n = sc.nextInt();
    int l=0;
    int sum=0;
    while(n>0)
    {
      int d= n%10;
      if(d>0)
      {l++;}
      n=n/10;
    }System.out.println("Number of digit :"+l);
    
	}
}
