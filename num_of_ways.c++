class Solution {
public:
    int numWays(int steps, int arrLen) {
        int m = steps;
        int n = min(steps / 2 + 1, arrLen);
        
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        dp[0][0] = 1;
        
        int mod = 1000000007; 
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < n - 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        
        return dp[m][0];
    }
};
