#include<iostream>
using namespace std;
  long long int a[1000001],sm1[1000001],sm2[1000001];
int main() {
 int t,n;
 long long int max=-1,area;
 
  
	cin>>t;
	while(t--)
	{
	    max=-1;
	    area=0;
	    cin>>n;
	    
	   
	   memset(sm1,-1, sizeof(sm1)); 

	   memset(sm2,-1,sizeof(sm2));
	  
	    for(int i=0;i<n;i++)
	        {
	            cin>>a[i];
	        }
	   
	    s1.push(0);
	    s2.push(n-1);
	    for(int i=1;i<n;i++)
	    {
	        if(a[s1.top()]>a[i])
	        {
	            while(!s1.empty()&&a[s1.top()]>a[i])
	            {
	                
	                sm1[s1.top()]=i-1;
	                s1.pop();
	            }
	        }
	        s1.push(i);
	    }
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        if(a[s2.top()]>a[i])
	        {
	            while(!s2.empty()&&a[s2.top()]>a[i])
	            {
	                sm2[s2.top()]=i+1;
	                s2.pop();
	            }
	        }
	        
	        s2.push(i);
	    }
	   
	    for(int i=0;i<n;i++)
	    {
	        if(sm1[i]==-1)
	        sm1[i]=n-1;
	        if(sm2[i]==-1)
	        sm2[i]=0;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	      area=(sm1[i]-sm2[i]+1)*a[i];
	      if(max<area)
	      max=area;
	      
	    }
	    while(!s1.empty())
	    {
	        s1.pop();
	    }
	    while(!s2.empty())
	    {
	        s2.pop();
	    }
	    
	     cout<<max<<endl;
	}
	return 0;
}
