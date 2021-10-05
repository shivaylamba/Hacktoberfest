class Solution {
public:
    int countVowelStrings(int n) {
        // dp[n][k] here will mean the number of strings 
        // constructed by considering at most k digits
        // vowels are a , e , i , o , u 
        vector<int> dp{0,1,1,1,1,1};
        for(int i = 1 ; i<=n ; i++)
        {
            // we start with one characted
            for(int k = 1 ; k<=5 ; k++)
            {
                dp[k]+=dp[k-1];
            }
        }
        return dp[5];
    }
};