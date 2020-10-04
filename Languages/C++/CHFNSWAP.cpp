//author: kvv1618
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll s=n*(n+1)/2;
	    if(s%2!=0)
	    {
	        cout<<0<<endl;
	        continue;
	    }
	    ll ans=((ll)(sqrt(4*s+1)-1))/2;
	    if (sqrt(4*s+1) == (ll)sqrt(4*s+1))
	    {
	        ll a2=n-ans;
	        ans=(ans*(ans-1)/2)+((a2)*(a2-1)/2)+a2;
	    }
	    else
	    {
	        ans=n-ans;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
