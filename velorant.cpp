#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void solve(ll n,ll h){
    ll arr[n];
    ll c = 0;
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if(arr[n-1]>=h){
        c=1;

    }
    else{
         c += 2*(h/(arr[n-1]+arr[n-2]));
        if(h%(arr[n-1]+arr[n-2])==0) c+=0;
        else if (h%(arr[n-1]+arr[n-2])<=arr[n-1]) c+=1;
        else c+=2;

        }
    cout<<c<<endl;
    return;
}
int main(){
    ll t = 0;
    cin>>t;
    while(t--){
        ll n,h;
        cin>>n>>h;
        solve(n,h);
    }
    return 0;
}
