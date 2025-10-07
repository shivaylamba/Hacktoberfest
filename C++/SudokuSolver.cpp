#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Check if placing 'num' at position (row, col) is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == num || board[i][col] == num)
                return false;
        }

        // Check 3x3 subgrid constraint
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i)
        {
            for (int j = startCol; j < startCol + 3; ++j)
            {
                if (board[i][j] == num)
                    return false;
            }
        }
        return true;
    }

    // Recursive function to solve the Sudoku
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                // If cell is empty, try all numbers 1–9
                if (board[row][col] == '.')
                {
                    for (char num = '1'; num <= '9'; ++num)
                    {
                        // Check if current number can be placed
                        if (isValid(board, row, col, num))
                        {
                            board[row][col] = num;

                            // Recursively try to solve with this placement
                            if (solve(board)) 
                                return true;

                            // If failed, backtrack
                            board[row][col] = '.';
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Solved completely
    }

    // Public function to start solving
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

// Sample test in main
int main()
{
    // Example Sudoku puzzle (empty cells are '.')
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "Original Sudoku:\n";
    for (auto &row : board)
    {
        for (auto &cell : row)
            cout << cell << " ";
        cout << endl;
    }

    Solution solver;
    solver.solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    for (auto &row : board)
    {
        for (auto &cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
