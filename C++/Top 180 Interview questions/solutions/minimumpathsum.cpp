class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        const int INF = 1e9 + 5;
        vector<vector<int>> dp(h, vector<int>(w));
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                // soure se source jaane me minimum distance is 0
                else
                {
                    dp[i][j] = grid[i][j] + min((i==0?INF:dp[i-1][j]),(j==0?INF:dp[i][j-1]));
                }
            }
        }
        return dp[h-1][w-1];
    }
};