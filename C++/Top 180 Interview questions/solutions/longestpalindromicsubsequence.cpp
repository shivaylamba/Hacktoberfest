class Solution {
public:
    int func(string s1, string s2,int n)
    {
        int dp[n+1][n+1];
        for(int i = 0 ; i<=n;i++)
        {
            for(int j = 0; j<=n ; j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                {
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);   
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2= s1;
        reverse(s2.begin(), s2.end());
        return func(s1,s2,n);
    }
};