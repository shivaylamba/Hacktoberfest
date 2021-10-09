#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

vector<vector<int>> row;
vector<vector<int>> col;
vector<vector<vector<int>>> block;
class Solution
{
public:
    //Function to find a solved Sudoku.
    bool solve(int board[N][N], int r, int c)
    {
        if (r == 9)
        {
            return 1;
        }
        if (board[r][c] != 0)
        {
            if (c == 8)
            {
                r = r + 1;
                c = 0;
            }
            else
            {
                c += 1;
            }
            return solve(board, r, c);
        }
        for (int j = 0; j < 9; j++)
        {
            if (row[r][j] == 1 or col[c][j] == 1 or block[r / 3][c / 3][j] == 1)
            {
                continue;
            }
            else
            {
                board[r][c] = j + 1;
                row[r][j] = 1;
                col[c][j] = 1;
                block[r / 3][c / 3][j] = 1;
                if (solve(board, r, c))
                {
                    return 1;
                }
                board[r][c] = 0;
                row[r][j] = 0;
                col[c][j] = 0;
                block[r / 3][c / 3][j] = 0;
            }
        }
        return 0;
    }
    bool SolveSudoku(int grid[N][N])
    {
        row = vector<vector<int>>(9, vector<int>(9, 0));
        col = vector<vector<int>>(9, vector<int>(9, 0));
        block = vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(9, 0)));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] != 0)
                {
                    row[i][grid[i][j] - 1] = 1;
                    col[j][grid[i][j] - 1] = 1;
                    block[i / 3][j / 3][grid[i][j] - 1] = 1;
                }
            }
        }
        return solve(grid, 0, 0);
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}