/*
Maximum Connected group
You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.
Examples :
Input: grid = [1, 1]
             [0, 1]
Output: 4
Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
[1, 1]
[1, 1]
Input: grid = [1, 0, 1]
             [1, 0, 1]
             [1, 0, 1]
Output: 7
Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
[1, 0, 1]
[1, 0, 1]
[1, 1, 1]
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
Constraints:
1 <= size of the grid<= 500
0 <= grid[i][j] <= 1
*/
class Solution {
  public:
    int dfs(vector<vector<int>>& grid,int i,int j,int index){
        //base case
         int n= grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] !=1){
            return 0;
        }
        //recursive
        grid[i][j] = index;
        int count = dfs(grid,i+1,j,index)+dfs(grid,i-1,j,index)
        +dfs(grid,i,j-1,index)+dfs(grid,i,j+1,index);
        return count +1;
    }
    void neighbours(vector<vector<int>>& grid,int i,int j,set<int> & s){
        int n= grid.size();
        if(i>0){
            s.insert(grid[i-1][j]);
        }
        if(j>0){
            s.insert(grid[i][j-1]);
        }
        if(i<n-1){
            s.insert(grid[i+1][j]);
        }
        if(j<n-1){
            s.insert(grid[i][j+1]);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // codeGenius
        int n=grid.size(),res=0,index=2,count;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mp[index]=dfs(grid,i,j,index);
                    res=max(res,mp[index++]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>s;
                    neighbours(grid,i,j,s);
                    count=1;
                    for(int i:s){
                        count+=mp[i];
                        
                    }
                    res=max(res,count);
                }
            }
        }
        return res;     
    }
};