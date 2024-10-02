/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.
Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
Constraints:
1 <= n <= 1690
*/
/*
        DP Approach
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 0 ,dp[1] = 1;
        int n2 = 1 ,n3 = 1 , n5 = 1;
        for(int i  =2;i<=n;i++){
            int a2 = dp[n2]*2 , a3 = dp[n3]*3 , a5 = dp[n5]*5;
            dp[i] = min({a2,a3,a5});
            if(dp[i]==a2) n2++; 
            if(dp[i]==a3) n3++; 
            if(dp[i]==a5) n5++; 
        }
        return dp[n];
    }
};