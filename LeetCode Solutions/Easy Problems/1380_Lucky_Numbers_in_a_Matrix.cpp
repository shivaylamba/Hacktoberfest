/*
1380. Lucky Numbers in a Matrix
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
Example 1:
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:
Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
Constraints:
m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
*/
/*
    Approach -1
Time Complexity O(n*m)
Space Complexity O(m*n)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int x = 0 ,y=0;
        while(x<matrix.size()){
            int minRow = INT_MAX , maxCol = INT_MIN;
            for(int i = 0 ;i<matrix[x].size();i++){
                minRow = min(minRow,matrix[x][i]);
            }
            for(int j = 0 ;j<matrix.size();j++){
                maxCol = max(maxCol,matrix[j][y]);
            }
            if(minRow==maxCol) ans.push_back(matrix[x][y]);
            y++;
            if(y==matrix[x].size()){
                x++;
                y=0;
            }
        }
        return ans;
    }
};
/*
    Approach -2
Time Complexity O(n^2)
Space Complexity O(m*n)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        vector<int>v;
        for(int i=0;i<r;i++){
            int mini=INT_MAX;
            for(int j=0;j<c;j++){
                mini=min(mini,m[i][j]);
            }
            v.push_back(mini);    
        }
        for(int i=0;i<c;i++){
            int maxi=INT_MIN;
            for(int j=0;j<r;j++){
                maxi=max(maxi,m[j][i]);
            }
            v.push_back(maxi);    
        }
        vector<int>ans;
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]==v[j]){
                    ans.push_back(v[i]);
                }
            }
        }
        return ans;
    }
};