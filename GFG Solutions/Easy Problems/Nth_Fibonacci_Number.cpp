/*
Nth Fibonacci Number
Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Note: for the reference of this question take first fibonacci number to be 1.

Example 1:

Input: 
n = 2
Output: 
1 
Explanation: 
1 is the 2nd number of fibonacci series.
Example 2:

Input: 
n = 5
Output: 
5
Explanation: 
5 is the 5th number of fibonacci series.
Your Task:  
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=105
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int d= 1000000007;
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
     vector<int> dp(n+1);
     dp[0]=0 ;
     dp[1]=1;
     for(int i=2;i<=n;i++){
         dp[i]=(dp[i-1]%d+dp[i-2]%d)%d;
     }
     return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends