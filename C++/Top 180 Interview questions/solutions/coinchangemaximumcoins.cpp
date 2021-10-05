// maximum number of ways to use coins so that they fill up the entire value

int main()
{
	int n; 
	int coins[n];
	int w;
	// here size of array is same as the length of rod{
	 int t[n+1][w + 1];
	 for(int i = 0 ; i< w + 1 ; i++)
	    t[0][i] = 0;
	for(int i = 0 ; i< n + 1 ; i++)
	    t[i][0] = 1;
	 for(int i = 1 ; i<n+1 ; i++)
	 {
	     for(int j = 1; j < sum+1 ; j++)
	     {-
	         if(coins[i-1]<=w)
	             t[i][j] = (t[i][j- coins[i-1]]+t[i-1][j]);
	         else
	            t[i][j] = t[i-1][j];
	     }
	 }
	 return t[n][w];
}
}