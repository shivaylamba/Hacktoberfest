/*
Count ways to N'th Stair(Order does not matter)
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n = 4:- {1 2 1},{2 1 1},{1 1 2} are considered same.
Examples :
Input: n = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.
Input: n = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.
Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
Constraints:
1 ≤ n ≤ 104
*/
class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		     vector<int>dp(n+1,0);
            dp[0]=1;
            dp[1]=1;
            for(int i=2;i<=n;i++){
                dp[i]=min(dp[i-1],dp[i-2])+1;
            }
            return dp[n];
		}
};