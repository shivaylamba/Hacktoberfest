//Solution for Codechef September long Division 2
//https://www.codechef.com/SEPT20B/problems/ADAMAT
//author: kvv1618
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n][n];
	    int v[n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            if(i==0)
	            {
	                if(a[i][j]==j+1)
	                {
	                    v[j]=0;
	                }
	                if(a[i][j]!=j+1)
	                {
	                    v[j]=1;
	                }
	            }
	        }
	    }
	    int c=0;
	    for(int i=1;i<n-1;i++)
	    {
	        if(v[i]!=v[i+1])
	        {
	            c++;
	        }
	    }
	    if(v[n-1]==1)
	    c++;
	    cout<<c<<endl;
	}
	return 0;
}
