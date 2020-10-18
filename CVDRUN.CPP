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
int p[1001];
void solve(){
    fill(p,0);
    int n,x,k,y;
    cin>>n>>k>>x>>y;
    p[x]=1;
    while(true){
        x=(x+k)%n;
        if(p[x])
            break;
        else
            p[x]=1;
    }
    if(p[y])
        YES
    else
        NO
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
