/*
Largest square formed in a matrix
Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.
Examples:
Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
Explanation: 
The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: n = 2, m = 2
mat = [[0, 0], 
       [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
Constraints:
1 ≤ n, m ≤ 500
0 ≤ mat[i][j] ≤ 1 
*/

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i =0;i<n;i++) dp[i][0] = mat[i][0];
        for(int i=0;i<m;i++) dp[0][i] = mat[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1) dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                else dp[i][j] = 0;
            }
        }
        
        int ans = dp[0][0] , row = 0 , col = 0;
        
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                    row = i ;
                    col = j;
                }
            }
        }
        return ans;
    }
};