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
		for(int i=0;i<t;i++)
		{
		    int n=sc.nextInt();
		    int a[]=new int[n];
		    long m=n;
		    long k=sc.nextLong();
	        int f=0;
		    for(int j=0;j<n;j++)
		        a[j]=sc.nextInt();
		    if(k>3*m){
		       if(n%2==1) a[n/2]=0;
 		       k=k%(3*m);
 		    }
            int k1=(int)k;
		    for(int j=0;j<k1;j++){
		        a[j%n]=a[j%n]^a[n-1-(j%n)];
		    } 
		    for(int j=0;j<n;j++) 
		    System.out.print(a[j]+" ");
		      
		    System.out.println();  
	    }
		
	}
}
