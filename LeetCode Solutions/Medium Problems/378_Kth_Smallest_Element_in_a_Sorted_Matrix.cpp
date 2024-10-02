/*
378. Kth Smallest Element in a Sorted Matrix
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 */
class Solution {
public:

    int countSmallorEqual(vector<vector<int>>& matrix, int num)
    {
        int r = 0;
        int c = matrix[0].size() - 1;
        int count = 0;

        while(r < matrix.size() && c >= 0)
        {
            if(matrix[r][c] <= num)
            {
                count += c + 1;  //number of elements along this row
                ++r;
            }
            else
            {
                --c;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int min_elem = matrix[0][0];
        int max_elem = matrix[m-1][n-1];

        while(min_elem < max_elem)
        {
            int mid = min_elem + (max_elem - min_elem) / 2;
            int count = countSmallorEqual(matrix, mid);
            
            if(count < k)
            {
                min_elem = mid + 1;
            }
            else
            {
                max_elem = mid;
            }
        }

        return min_elem;
    }
};
//------------------------------------------------------------------------------------//
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() ,row = 0 , col = 0 ;
        vector<int> ans;
        while(row <n && col < n){
            ans.push_back(matrix[row][col]);
            col++;
            if(col == n ){
                row++;
                col= 0;
            }
        }
        sort(ans.begin(),ans.end());

         return ans[k-1];
    }
};