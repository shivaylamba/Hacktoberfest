//Solution for Codechef September Long challenge 2020 Division 2
//author: kvv1618
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	int k,t;
	cin>>k>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll s=n*(n+1)/2;
	    ll te=0,l=s/2;
	    cout<<s-(2*(s/2))<<endl;
	    vector<ll>v;
	    for(ll i=n;i>0;i--)
	    {
	        if(te+i<=l)
	        {
	            v.push_back(1);
	            te+=i;
	        }
	        else
	        {
	            v.push_back(0);
	        }
	    }
	    for(ll i=n-1;i>=0;i--)
	    cout<<v[i];
	    cout<<endl;
	}
	return 0;
}
