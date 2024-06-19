#include <iostream>
#include <vector>
#include <map>

#define ll long long int
#define read(a) ll a; cin >> a;
#define readstr(s) string s; cin >> s;
#define readarr(a,l) ll a[l]; for(ll i=0;i<l;i++) cin>>a[i];
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define readmtrx(i,j,a,b) ll arr[a][b]; for(ll i=0;i<a;i++) for(ll j=0;j<b;j++) cin>>arr[i][j];
#define v(pi) vector<ll>pi
#define vp(pi) vector<pair<ll,ll>>pi
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define pb(p) push_back(p)
#define mp make_pair
#define mi(lol) map<ll,ll>lol

using namespace std;

void pigeonhole_sort(ll arr[], ll n) {
    ll min_val = arr[0], max_val = arr[0];
    
    // Find minimum and maximum values in the array
    for (ll i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    
    ll range = max_val - min_val + 1;
    vector<ll> holes[range];
    
    // Distribute elements into pigeonholes
    for (ll i = 0; i < n; i++) {
        holes[arr[i] - min_val].push_back(arr[i]);
    }
    
    // Gather elements from pigeonholes back to original array
    ll index = 0;
    for (ll i = 0; i < range; i++) {
        for (ll j = 0; j < holes[i].size(); j++) {
            arr[index++] = holes[i][j];
        }
    }
}

int main() {
    fast;
    
    read(a); // Number of elements
    readarr(arr, a); // Array elements
    
    pigeonhole_sort(arr, a);
    
    cout << "Sorted order is : ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
