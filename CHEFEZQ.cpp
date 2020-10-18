#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define fill(arr,value) memset(arr,(value),sizeof(arr))
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define print(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef set<int> si;
void solve(){
    ll n,x,ans=-1;
    cin>>n>>x;
    ll a[n];
    FOR(i,0,n)
        cin>>a[i];
    bool flag=false;
    FOR(i,0,n-1){
        if(a[i]>=x){
            a[i+1]+=a[i]-x;
            a[i]=x;
        }
        else{
            //cout<<"YO\n";
            ans=i+1;
            flag=true;
            break;
        }
    }
    //cout<<a[n-1]<<endl;
    if(flag){
        cout<<ans<<endl;
    }
    else{
        if(a[n-1]<x){
            //cout<<"YO\n";
            ans=n;
        }
        else{
            //cout<<"YO\n";
            ans=n+ceil(a[n-1]/x);
        }
        cout<<ans<<endl;
    }
}
int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
