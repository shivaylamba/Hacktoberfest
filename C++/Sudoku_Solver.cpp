class Solution {
public:
    bool isValid(int row,int col,char ch,vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch)
                return false;\
            if(board[row][i]==ch)
                return false;
        }
        int box_row=3*(row/3);
        int box_col=3*(col/3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[box_row+i][box_col+j]==ch)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        //1-> find the blank space
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(i,j,c,board))
                        {
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            board[i][j]='.';    
                        }                       
                    }
                    return false;   
                }
            }
        }
        return true;  
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board); 
    }
};
