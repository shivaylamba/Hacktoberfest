/*
840. Magic Squares In Grid
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
Example 1:
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
while this one is not:
In total, there is only one magic square inside the given grid.
Example 2:
Input: grid = [[8]]
Output: 0
Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/
class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
        if(i + 2 < grid.size() && j+2 < grid[i].size()){
            int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            int diag2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
            if(
                (col1 == col2) &&
                (col1 == col3) &&
                (col1 == row1) && 
                (col1 == row2) &&
                (col1 == row3) &&
                (col1 == diag1) &&
                (col1 == diag2)) {
                    set<int> s({1,2,3,4,5,6,7,8,9});
                    for(int r = 0 ; r < 3 ; r++){
                        for(int c = 0; c < 3 ; c++){
                            s.erase(grid[i + r][j + c]);
                        }
                    }
                    return s.empty();
            }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size() ; j++){
                if(isMagicSquare(grid, i, j)){
                    result++;
                }
            }
        }
        return result;
    }
};