//Solution for Codechef September Long challenge 2020 Division 2
//https://www.codechef.com/SEPT20B/problems/FINXOR
//author: kvv1618
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,k=0,j=2,ans=0;
    	vector<ll>a,v,tt;
    	a.push_back(1);
	    cin>>n;
	    if(n%2==0)
	    {
	        for(ll i=0;i<19;i++)
    	    {
    	        a.push_back(a[k++]+j);
    	        j*=2;
    	    }
    	    /*for(ll i=0;i<a.size();i++)
    	    {
    	        v.push_back((1^a[i])+(2^a[i])+(3^a[i])+(4^a[i])+(5^a[i])+(6^a[i])+(7^a[i])+(8^a[i]));
    	        cout<<v[i]<<" ";
    	    }
    	    cout<<endl;*/
    	    ll te=20;
    	    k=0;
    	    while(te--)
    	    {
    	        cout<<1<<" "<<a[k++]<<endl;
    	        fflush(stdout);
    	        ll x;
    	        cin>>x;
    	        if(x==-1)
    	        return 0;
    	        v.push_back(x);
    	    }
    	    if(v[0]%2!=0&&n%2==0)
    	    ans+=1;
    	    j=2;
    	    ll s=2;
    	    for(ll i=1;i<20;i++)
    	    {
    	        if(((((v[i-1]-v[i])/j)+n)/2)%2!=0)
    	        ans+=s;
    	        s*=2;
    	        j*=2;
    	    }
	    }
	    if(n%2!=0)
	    {
	        ll kv=1;
	        ll x,p=0,em=0;
	        for(int i=0;i<20;i++)
	        {
	            kv*=2;
	            cout << 1 << " " << kv-1 << endl;
	            fflush(stdout);
	            cin >> x;
	            if(kv==2)
	            {
	                if(x%2==0)  ans+=1;
	                else em+=1;
	                p=x-em;
	            }
	            else
	            {
	                ll ck=p-x+em;
	                ck=ck/(kv/2);
	                if(ck<0)
	                {
	                   ck=ck+n;
	                   ck/=(2);
	                   if(ck%2==1) ans+=(kv/2);
	                   else em+=(kv/2);
	                }
	                else
	                {
	                    ck=n-ck;
	                    ck/=2;
	                    if(ck%2==0) ans+=(kv/2);
	                    else em+=(kv/2);
	                }
	                p=x-em;
	           }
	       }
	    }
	    cout<<2<<" "<<ans<<endl;
	    fflush(stdout);
	    ll x;
	    cin>>x;
	    if(x==-1)
	    return 0;
	}
	return 0;
}
