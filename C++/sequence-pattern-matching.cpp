int lcs(string a, string b, int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(a[i - 1] == b[ j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

bool sequenceMatching(string a, string b) {
  int m = a.length();
  int n = b.length();
  
  int len = lcs(a, b, m, n);
  
  if(len == m) {
    return true;
  }
  else {
    return false;
  }
}
