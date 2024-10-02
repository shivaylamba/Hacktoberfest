/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
nput: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5
 

Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
//  Most Optimized Method
//  Time Complexity O(n*n)
//  Space Complexity O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int sum= 0;
        int r = mat.size() , c = mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==j || r-j-1==i){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
//  Most Optimized Method
//  Time Complexity O(n)
//  Space Complexity O(1)
     int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
          
                 sum+=mat[i][i];
                 sum+=mat[i][n-1-i];
            
        }
        if(n%2==1){
            sum-=mat[n/2][n/2];
        }

        return sum;
    }
};