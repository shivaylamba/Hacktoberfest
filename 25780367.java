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
		    int n=sc.nextInt();
		    int c[]= new int[n];
		    int h[]=new int[n];
		    int r[]=new int[n];
		    int qs[]=new int[n];
		    int qe[]=new int[n];
		    int sum[]=new int [n];
		    for(int j=0;j<n;j++)
		       { c[j]=sc.nextInt();
                 r[j]=0;} 
		    for(int j=0;j<n;j++)
		         h[j]=sc.nextInt();
		    for(int j=0;j<n;j++){
		         qs[j]=j-c[j];
		        if(qs[j]<=0) qs[j]=0;
		         qe[j]=j+c[j];
		        if(qe[j]>=n-1) qe[j]=n-1;
		    }
		    for(int j=0;j<n;j++){
		        sum[qs[j]]++;
		        if(qe[j]+1<n)  sum[qe[j]+1]--;
		    }
		    r[0]+=sum[0];
		for (int ji = 1; ji < n; ji++) 
        { 
            sum[ji] += sum[ji - 1]; 
            r[ji] += sum[ji]; 
        }    
		    int f=0,a=0;
		   Arrays.sort(h);
		   Arrays.sort(r);
		    //for(int k=0;k<n;k++)
		      //System.out.print(h[k]);
		    for(int k=0;k<n;k++){
		     // System.out.println(r[k]);
		   
		           if(h[k]==r[k])f++;
		               //h[q]=-1;
		               //System.out.println("ghghj");
		          //     break;}
		       }
    //if(f==0) {System.out.print(r[k]+"-"+k);
    //a=1; break;}
		    
		    if(f!=n) System.out.println("NO");
		    else System.out.println("YES");
		} 
		
	}
}