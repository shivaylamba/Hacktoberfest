class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        int height = mat.size();
        int width = mat[0].size();
        for(int i = 0 ; i < height ; i++)
        {
        for(int j = 0 ; j < width ; j++)
        {
            mp[i-j].push(mat[i][j]);
        }
        }
        for(int i = 0 ; i < height ; i++)
        {
        for(int j = 0 ; j < width ; j++)
        {
            mat[i][j] = mp[i-j].top();
            mp[i-j].pop();
        }
        }
        return mat;
    }
};