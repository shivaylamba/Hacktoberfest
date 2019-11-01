/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class me
{	
	static Long gcd(Long a, Long b){
		if(b==0)
			return a;
		return(gcd(b, a%b));
	}
	static Long lcm(Long a, Long b){
		return ((a*b)/gcd(a , b));
	}
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
			int testcases=sc.nextInt();
			while(testcases-->0){
				long A=sc.nextLong();
				long B=sc.nextLong();
				System.out.println(gcd(A , B)+" "+lcm(A , B));
			}	
	}
}