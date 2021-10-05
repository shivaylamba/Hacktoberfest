class Solution {
public:
    void solve (int i, int j , vector<vector<int>>& grid,int n , int m)
    {
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
        grid[i][j] = 0;
        solve(i+1,j,grid,n,m);
        solve(i,j+1,grid,n,m);
        solve(i-1,j,grid,n,m);
        solve(i,j-1,grid,n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
     int rows = grid.size();
     if(rows==0) return 0;
     int count = 0;
      int column = grid[0].size();
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < column ; j++)
            {
                if(i==0 || j==0 || i==(rows - 1) || j == (column - 1))
                   solve(i,j,grid,rows,column);
            }
        }
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < column ; j++)
            {
                if(grid[i][j]==1) 
                    count++;
            }
        }
        return count;
    }
};