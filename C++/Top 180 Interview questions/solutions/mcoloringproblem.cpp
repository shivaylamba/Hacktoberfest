class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    // we need not return anything just need to fill the board
    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0 ; i < board.size(); i++)
        {
            for(int j = 0 ; j <board[0].size(); j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c = '1'; c <= '9' ; c++)
                    {
                        if(istrue(i,j,board,c))
                        {
                            board[i][j]=c;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }// this is how you loop in the characters
                    return false;
                }// if loop ends
            } // j for loop ends
        }// first for loop ends
        return true;
    }
    bool istrue(int row, int col, vector<vector<char>>& board, char c)
    {
        // we need to iterate in the entire board
        for(int i = 0 ; i < 9 ; i ++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
            if(board[3 * (row/3) + i / 3][ 3 *(col/3) + i % 3] == c)
                return false;
        }
        return true;
    }
};