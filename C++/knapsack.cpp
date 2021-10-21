// dp function for knapsack problem 

int knapSack(int W, int wt[], int val[], int n){
    
    //created 2-D matrix
    vector<vector<int>> dp(n+1, vector<int>(W+1));
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){

            //base case
            if(i==0 || j==0){
                dp[i][j]= 0;
            }
            else if(wt[i-1]<=W){        // filling matrix 
                dp[i][j]= max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    // returning the ans stored in the last cell
    return dp[n][W];
}
