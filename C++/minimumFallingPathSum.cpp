// Question - https://leetcode.com/problems/minimum-falling-path-sum/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

int minFallingPathSum(vector<vector<int>>& mat) {
	int n = mat.size(), m = mat[0].size();
	int dp[n][m];
	int ans = 102;
	for (int j = 0; j < m; j++)    dp[n - 1][j] = mat[n - 1][j], ans = min(ans, dp[n - 1][j]);
	if (m == 1)
		return ans;
	ans = INT_MAX;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = dp[i + 1][j];
			if (j - 1 >= 0 && dp[i + 1][j - 1] < dp[i][j])  dp[i][j] = dp[i + 1][j - 1];
			if (j + 1 < m && dp[i + 1][j + 1] < dp[i][j])  dp[i][j] = dp[i + 1][j + 1];
			dp[i][j] += mat[i][j];
			if (!i)
				ans = min(ans, dp[i][j]);
		}
	}
	return ans;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> grid = {
		{2, 1, 3},
		{6, 5, 4},
		{7, 8, 9}
	};
	int ans = minFallingPathSum(grid);
	cout << "Min falling path sum of the given grid is: " << ans << "\n";

	return 0;
}
