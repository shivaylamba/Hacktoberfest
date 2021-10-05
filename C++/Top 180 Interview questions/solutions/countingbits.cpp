class Solution {
public:
    vector<int> countBits(int n) {
        // dp[index] = dp[index - offset] + 1;
        int offset = 1;
        vector<int> dp(n+1);
        for(int index = 1 ; index <=n ; index++)
        {
            if(offset * 2 == index)
                offset*=2;
            dp[index] = dp[index - offset] + 1;
        }
        return dp;
        // see discussion session
    }
};