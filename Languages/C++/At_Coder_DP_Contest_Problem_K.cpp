#include<bits/stdc++.h>

using namespace std;

bool dp[100005];

void solve() {
	ll n, k;
	cin >> n >> k;
	std::vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(dp, false, sizeof dp);

	for (int i = 1; i <= k; i++) {
		for (auto x : v) {
			if (i >= x && dp[i - x] == false)
				dp[i] = true;
		}
	}

	if (dp[k])
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}


int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
