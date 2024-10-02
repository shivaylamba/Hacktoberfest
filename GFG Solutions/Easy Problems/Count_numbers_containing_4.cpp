/*
Count numbers containing 4
You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.
Examples:
Input: n = 9
Output: 1
Explanation: 4 is the only number between 1 to 9 which contains 4 as a digit.
Input: n = 44
Output: 9
Explanation: 4, 14, 24, 34, 40, 41, 42, 43 & 44, there are total 9 numbers containing 4 as a digit.
Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(1)
Constraints:
1 <= n <= 105
*/
/*
    DYNAMIC PROGRAMMING
    An Efficient Solution using DP
Time complexity : O(n log n)
Space complexity : O(n)
*/
class Solution {
  public:
  bool have4(int n){
      while(n){
          if(n%10==4) return 1;
          n/=10;
      }
      return 0;
  }
    int countNumberswith4(int n) {
        // code here
        int count =0;
        vector<int> dp(n+1,0);
        if(n<4) return count;
        for(int i = 4;i<=n;i++){
            if(dp[i]){      count++;    continue;   }
            if(have4(i)){
                dp[i] = true;
                count++;
            }
        }
        return count ;
    }
};
/*
    OPTIMZED APPROACH
Time Complexity: O(N log N) ,as complexity of function countNumbersWith4(int n)
                 is O(N) and as it calling function has4(int x) N times whose 
                 complexity is O(log N) ,thus overall complexity is O(N log N).
Auxiliary Space: O(1),  since no extra space used.
*/
class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
        if(n<4) return count;
        for(int i=4;i<=n;i++){
            int a = i;
            while(a){
                if(a%10==4) {
                    count++;
                    break;
                }
                a/=10;
            }
        }
        return count ;
    }
};