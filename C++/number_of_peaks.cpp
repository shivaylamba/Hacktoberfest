#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) x.begin(), x.end()
#define printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
#define printMap(mp) {for(auto &p : mp) cout << p.first <<" " <<p.second <<endl;}
#define MOD 1000000007
#define hM 9999999900000001
#define inf 1e17
#define PI 3.14159265358979323846264338327950288


int A [] = {0, 0, 10, 60, 270, 1080, 4050, 14580, 51030, 174960, 590490};
void solve(int T) {
  int n;
  cin >> n;
  cout << A[n-1] <<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
