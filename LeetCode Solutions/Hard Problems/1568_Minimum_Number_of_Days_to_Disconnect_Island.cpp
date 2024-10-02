/*
1568. Minimum Number of Days to Disconnect Island
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.
Example 1:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:
Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.
*/
class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int gc = 0;

    int solve(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        int cnt =0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {

                    cnt++;

                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;

                        q.pop();
                        gc++;

                        for(int i=0;i<4;i++)
                        {
                            int nx = r + dx[i];
                            int ny = c + dy[i];

                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1 && !vis[nx][ny])
                            {
                                q.push({nx,ny});
                                vis[nx][ny] = 1;
                            }
                        }


                    }
                    
                }
            }
        }


        return cnt;

    }
    int minDays(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int tot = solve(grid);

        if(tot==1 && gc ==1)
        {
            return 1;
        }
        if(tot > 1 || tot==0)
        {
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;

                    int cnt = solve(grid);

                    if(cnt >1)
                    {
                        return 1;
                    }

                    grid[i][j] =1;
                }
            }
        }

        return 2;

    }
};