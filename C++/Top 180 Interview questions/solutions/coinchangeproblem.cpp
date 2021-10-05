void function(int coins[], int w )
{
	int n = coins.size();
	int dp[n+1][w+1];
	// along rows we will have coins
	// along column we will have sum
	for(int i =1 ; i<=n; i++)
	{
		dp[i][0] = 1;
	}
	for(int j = 0 ; j<=w;j++)
	{
		dp[0][j]=0;
	}
	for(int i = 1; i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(coins[i-1]<=w)
			{
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}