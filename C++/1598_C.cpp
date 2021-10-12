#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

 
void solve(){
    ll n;cin>>n;
    ll a[n+1];
    ll sum=0;
    map<ll,ll>mp1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp1[n*a[i]]++;
        sum+=a[i];
        a[i]*=n;
    }
    sum*=2;
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(mp1.find(sum-a[i])==mp1.end()){
            continue;
        }else{
            auto it=mp1.find(sum-a[i]);
            if(sum-a[i]==a[i]){
                cnt+=(it->second)-1;
            }else{
                cnt+=it->second;
            }
        }
    }
    cout<<cnt/2<<endl;
 
    
 
    
 
}
 
 
int main() {

    ll int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
