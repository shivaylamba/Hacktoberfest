/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/
class Solution {
public:
// Otpimized solution
  // Time Complexity O(log(row*col))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
 int col = matrix[0].size();
 int st = 0;
 int en = row*col-1;
 int mid = st + (en -st)/2 ;
 while(st<=en){
    int element = matrix[mid/col][mid%col];
    if(element == target){
        return 1;
        }
    else if(element>target){
         en =mid-1;
    }
    else{
         st = mid+1;
    }
mid = st+ (en -st)/2 ;
 }
 return 0;
    }
//Brute force solution
//Time complexity: O(n*m)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
        
    }
};