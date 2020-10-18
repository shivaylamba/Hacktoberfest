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
bool poweroftwo(int x){
    return x&&(!(x&(x-1)));
}
void solve(){
    int n;
    cin>>n;
    if(poweroftwo(n) && n!=1){
        cout<<-1<<endl;
    }
    else if(n==1)
        cout<<1<<endl;
    else{
        cout<<"2 3 1 ";
        FOR(i,4,n+1){
            if(poweroftwo(i)){
                cout<<i+1<<" "<<i<<" ";
                i++;
            }
            else
                cout<<i<<" ";
        }
        cout<<endl;
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
