/*
1905. Count Sub Islands
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
Return the number of islands in grid2 that are considered sub-islands.
Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
Constraints:
m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/
class Solution {
public:
    int n, m;
    bool flag;
    bool vst[505][505];
    vector<vector<int>> grid_i, grid_ii;
    void dfs(int i, int j)
    {
        if(i < 0 or j < 0 or i >= n or j >= m or !grid_ii[i][j] or vst[i][j]) return;

        vst[i][j] = true;
        if(!grid_i[i][j]) flag = false;

        dfs(i+1, j);
        dfs(i, j+1);
        dfs(i-1, j);
        dfs(i, j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        grid_i = grid1, grid_ii = grid2;
        n = grid1.size(), m = grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vst[i][j] and grid_ii[i][j])
                {
                    flag = true;
                    dfs(i, j);
                    ans += flag;
                }
            }
        }
        return ans;
    }
};