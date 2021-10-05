int dp[501][501];
    bool ispalindrome(string s, int i ,int j)
    {
        if(i==j)
            return true;
        if(i>j)
        // empty substring
            return true;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s, int i , int j)
    {
        if(i >= j)
            return 0;
            // if empty substring no partition
            // if single character no partition
            
        if(ispalindrome(s,i,j))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        // if it is already a palindrome we need not make any cuts
        //k can go from i to j as well i to j - 1 as well
        // as we can have palindrome on 1 character of the string
        int ans = INT_MAX;
        int left;
        int right;
        for(int k = i ; k < j ; k++)
        {
            if(dp[i][k]!=-1)
                left = dp[i][k];
            else
                left = solve(s,i,k);
            if(dp[k+1][j]!=-1)
                right = dp[k+1][j];
            else
                right = solve(s,k+1,j);
            int temp = left +right + 1;
            // +1 because we made a single cut
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        memset(dp,-1,sizeof(dp));
        return solve(str,0,n-1);
    }