#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
#define pb push_back
#define fore(n) for(int i = 0;i < n;i++)
#define forr(j,n) for(int i = j;i < n;i++)
#define vll vector<long long>
typedef long long ll;
#define vi vector<int>
 
ll checkPrime(ll n){
    for(ll i = 2;i <= sqrt(n);i++){
        if(n % i == 0)return i;
    }
    return n;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
// #ifdef LOCAL
//     freopen("a.in", "r", stdin);
// #endif
 
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        if(checkPrime(n) != n) cout<<"Yes its prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
 
    return 0;
}
