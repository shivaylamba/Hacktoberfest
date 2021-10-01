#include <iostream>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n],b[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	     b[0] = a[n-1];
	    for(int i=1;i<n;i++)
	    {
	        b[i] = a[i-1];
	        
	    }
	    for(int i=0;i<n;i++)
	    cout<<b[i]<<" ";
	    
	    cout<<endl;
	}
	return 0;
}