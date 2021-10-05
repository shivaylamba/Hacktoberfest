class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first we take the transpose of the given matrix
        int rows = matrix.size();
        int column = matrix[0].size();
        for(int i = 0 ; i < rows ; i++)
        {
            for (int j = 0; j < i ; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0 ; i < rows; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};