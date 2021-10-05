class Solution{
public:
    // here i , j and istrue is also changing
    int dp[201][201][2];
    int solve(string s, int i , int j , bool istrue)
    {
        if(i > j)
            return true;
        if(i==j)
        {
            if(istrue==true)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        if(dp[i][j][istrue]!=-1)
            return dp[i][j][istrue];
    int ans = 0;
    for(int k = i+1;k<=j-1; k=k+2)
    {
        int lt;
        if(dp[i][k-1][1]!=-1)
            lt = dp[i][k-1][1];
        else
            lt = solve(s,i,k-1,true);
        int rt;
        if(dp[k+1][j][1]!=-1)
            rt = dp[k+1][j][1];
        else
            rt = solve(s,k+1,j,true);
        int lf;
        if(dp[i][k-1][0]!=-1)
            lf = dp[i][k-1][0];
        else
            lf = solve(s,i,k-1,false);
        int rf;
        if(dp[k+1][j][0]!=-1)
            rf = dp[k+1][j][0];
        else
            rf = solve(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(istrue==true)
                ans = ans + lt*rt;
            else
                ans = ans + lf*rt + lf*rf + lt*rf;
        }
        else if(s[k]=='|')
        {
            if(istrue==true)
                ans = ans + lt*rt + lf*rt + lt*rf;
            else
                ans = ans +lf*rf;
        }
        else if(s[k]=='^')
        {
            if(istrue==true)
                ans = ans + lf*rt + lt*rf;
            else
                ans = ans +lt*rt + lf*rf;
        }
        dp[i][j][istrue] = ans % 1003;
    }
        return ans % 1003;
    }
    int countWays(int n, string s){
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,1);
    }
};