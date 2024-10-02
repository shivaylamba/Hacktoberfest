/*
Trail of ones
Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.
Example 1:
Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Example 2:
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111.  The strings with consecutive 1's are 011, 110 and 111.
Example 3:
Input: n = 5
Output: 19
Explanation: There are 19 strings having consecutive 1's.
Your Task:
You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1s in them.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
Constraints
2 <= n <= 105
*/
class Solution {
  public:
           const int d = 1e9+7;
   long power(long a,long b){
       long ans = 1;
       while(b>0){
           if(b%2==1) ans*=a;
           b>>=1;
           a*=a;
           a%=d;
           ans%=d;
       }
       return ans;
   }
    int numberOfConsecutiveOnes(int n) {
        // code here
        if(n==2) return 1;
        if(n==3) return 3;
        vector<long> dp(n+1);
        dp[2]=1;
        dp[3]=3;
        for(int i = 4;i<=n;i++){
         dp[i] = (dp[i-1] + power(2,i-2)%d + dp[i-2])%d;
        }
        return (int)dp[n];
    }
};