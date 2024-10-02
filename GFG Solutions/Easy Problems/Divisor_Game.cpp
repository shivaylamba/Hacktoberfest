/*
Divisor Game
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < n  and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.
Return true if and only if Alice wins the game, assuming both players play optimally.
Example 1:
Input:
n = 2
Output: True
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:
Input:
n = 3
Output: False
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
Your Task:
You don't need to read input or print anything. Your task is to complete the function divisorGame() which takes an integer n as a parameter and returns true if Alice wins the game.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ n ≤ 103
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool divisorGameSolve(int N, bool A, int dp[][2])
{
 
    // check if N=1 or N=3 then player B wins
    if (N == 1 or N == 3)
        return false;
 
    // check if N=2 then player A wins
    if (N == 2)
        return true;
 
    // check if current state already visited
    // then return the previously obtained ans
    if (dp[N][A] != -1)
        return dp[N][A];
 
    // check if currently it is player A's turn
    // then initialise the ans to 0
    int ans = (A == 1) ? 0 : 1;
 
    // Traversing across all the divisors of N
    // which are less than N
    for (int i = 1; i * i <= N; i++) {
 
        // check if current value of
        // i is a divisor of N
        if (N % i == 0) {
 
            // check if it is player A's turn
            // then we need at least one true
            if (A)
                ans |= divisorGameSolve(N - i, 0, dp);
 
            // Else if it is player B's turn
            // then we need at least one false
            else
                ans &= divisorGameSolve(N - i, 1, dp);
        }
    }
 
    // Return the current ans
    return dp[N][A] = ans;
}
    bool divisorGame(int n) {
        // code here
        
    int dp[n + 1][2];
 
    memset(dp, -1, sizeof(dp));
    return divisorGameSolve(n,1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends