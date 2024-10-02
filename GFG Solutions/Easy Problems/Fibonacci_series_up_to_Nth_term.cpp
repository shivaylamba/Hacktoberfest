/*
Fibonacci series up to Nth term
You are given an integer n, return the fibonacci series till the nth(0-based indexing) term. Since the terms can become very large return the terms modulo 109+7.

Example 1:

Input:
n = 5
Output:
0 1 1 2 3 5
Explanation:
0 1 1 2 3 5 is the Fibonacci series up to the 5th term.
Example 2:

Input:
n = 10
Output:
0 1 1 2 3 5 8 13 21 34 55
Explanation:
0 1 1 2 3 5 8 13 21 34 55 is the Fibonacci series up to the 10th term.
Your Task:
You don't need to read input or print anything. Your task is to complete the function Series() which takes an Integer n as input and returns a Fibonacci series up to the nth term.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraint:
1 <= n <= 105
*/
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int>ans(n+1);
        ans[0]=0;
        ans[1]=1;
        
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            int x= ans[i-1]+ans[i-2];
            x%=mod;
            ans[i]=x;
        }
        return ans;
    }
};
// Why This Code give Error
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
     int d = 10e9+7;
        vector<int> dp(n+1);
     dp[0]=0 ;
     dp[1]=1;
     for(int i=2;i<=n;i++){
         int x = dp[i-1]+dp[i-2];
        x%=d;
         dp[i]=x;
     }
     return dp;
    }
};