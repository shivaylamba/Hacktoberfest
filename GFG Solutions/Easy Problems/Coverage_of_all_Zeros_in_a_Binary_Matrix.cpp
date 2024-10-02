/*
Coverage of all Zeros in a Binary Matrix
Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(1)

Constraints:
1 <= matrix.size, matrix[0].size <= 100
*/

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans =0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    continue;
                }
                if(i-1>=0 and matrix[i-1][j]==1)
                ans++;
                if(i+1<n and matrix[i+1][j]==1)
                ans++;
                if(j-1>=0 and matrix[i][j-1]==1)
                ans++;
                if(j+1<m and matrix[i][j+1]==1)
                ans++;
            }
        }
        return ans;
        
    }
};