int dp[101][10001];
int sol(int e,int f)
{
if(e==1 || f==1)
    return f;
if(dp[e][f]!=-1)
    return dp[e][f];
int ans = f;
int l = 1;
int h  = f;
while(l<=h)
{
    int k = (l+h) >> 1;
    int left = sol(e-1,k-1);
    int right = sol(e,f-k);
    int temp = 1 + max(left,right);
    if(left < right)
         l = k + 1;
     // we need to go to the max side
    else
        h =  k - 1; 
    ans = min(ans,temp);
}
return dp[e][f] = ans; 
}
int Solution::solve(int e, int f) {
    memset(dp,-1,sizeof(dp));
    return sol(e,f);
}
