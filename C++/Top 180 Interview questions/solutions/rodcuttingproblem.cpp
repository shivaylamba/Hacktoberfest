int main()
{
	int n; 
	int len = n;
	int prices[n];
	int length[n];
	// here size of array is same as the length of rod{
	 int t[n+1][len + 1];
	 for(int i = 0 ; i< len + 1 ; i++)
	    t[0][i] = INT_MIN;
	for(int i = 0 ; i< n + 1 ; i++)
	    t[i][0] = 0;
	 for(int i = 1 ; i<n+1 ; i++)
	 {
	     for(int j = 1; j < sum+1 ; j++)
	     {-
	         if(length[i-1]<=len)
	             t[i][j] = max(prices[i-1] + t[i][j- length[i-1]] ,t[i-1][j]);
	         else
	            t[i][j] = t[i-1][j];
	     }
	 }
	 return t[n][len];
}
}