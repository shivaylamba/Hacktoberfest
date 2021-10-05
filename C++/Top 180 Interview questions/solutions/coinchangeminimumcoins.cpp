class Solution {
public:
    int func(vector<int>& A, int B)
    {
     int n = A.size();
     int sum = B;
     int t[n+1][sum + 1];
     for(int i = 0 ; i< sum + 1 ; i++)
        t[0][i] = INT_MAX - 1;
    for(int i = 1 ; i< n + 1 ; i++)
        t[i][0] = 0;
    // for(int i = 1; i < sum + 1; i++)
    // {
    //     if(i%A[0]==0)
    //         t[1][i] = 1;
    //     else
    //         t[1][i] = INT_MAX-1;
    // }
     for(int i = 1 ; i<n+1 ; i++)
     {
         for(int j = 1; j < sum+1 ; j++)
         {
             if(A[i-1]<=j)
                 t[i][j] = min(t[i][j- A[i-1]] + 1,t[i-1][j]);
             else
                t[i][j] = t[i-1][j];
         }
     }
     return t[n][sum] >= INT_MAX -1  ? -1 : t[n][sum];
 }
    int coinChange(vector<int>& coins, int amount) {
       return func(coins,amount); 
    }
};