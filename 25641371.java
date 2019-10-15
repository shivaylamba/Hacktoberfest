/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
		    String s=sc.next();int c=0;
		    for(int j=0;j<s.length();j++)
		        if(s.charAt(j)=='1') c++;
		    if(c%2==0)
		    System.out.println("LOSE");
		    else System.out.println("WIN");
		} 
		
	}
}
