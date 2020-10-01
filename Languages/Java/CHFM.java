/* JULY CHALLENGE CHFM CODECHEF */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    
	    Scanner sc=new Scanner(System.in);
	    int t=sc.nextInt();
	    for(int i=0;i<t;i++)
	    {
	        double mean=0,newsum=0,num=0,sum=0,y=0;
	        int n=sc.nextInt();
	        int a[]=new int[n];
	        for (int j=0;j<n;j++)
	        {
	            a[j]=sc.nextInt();
	            sum=sum+a[j];
	        }
	        mean=sum/n;
	        newsum=mean*(n-1);
	        num=sum-newsum;
	        for(int j=0;j<n;j++)
	        {
	            if(num==a[j]){y++;
	            System.out.println(j+1);
	                break;
	            }
	        }
	        if(y==0)
	        System.out.println("Impossible");
	    }
	}
}
	        
	        
