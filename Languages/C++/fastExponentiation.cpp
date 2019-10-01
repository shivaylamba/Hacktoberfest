#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int x,n,ans=1;
  cin>>x>>n;

  while(n>0)
  {
    if(n&1)
    {
      ans=ans*x;
      n=n-1;
    }
    else
    {
      x=x*x;
      n=n/2;

    }
  }
  cout<<ans;
}

******************************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll x,ll n){
    
    if(n==0){
        return 1;
    }

    ll simpleAns=power(x,n/2);
    simpleAns *= simpleAns;

    if(n&1){
        simpleAns *= x;
    }

    return simpleAns;
}




int main()
{
  long long int x,n;
  cin>>x>>n;

  ll ans=power(x,n);
  cout<<ans;
}
