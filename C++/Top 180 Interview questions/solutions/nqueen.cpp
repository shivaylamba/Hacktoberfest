class Solution {
public:
    bool issafe(int row, int col,vector<string>& board, int n)
    {
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col>=0)
        {
           if(board[row][col]=='Q') return false;
            col--;  
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0)
        {
           if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void func(int col, vector<vector<string>>& ans, vector<string>& board, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int i = 0 ; i <  n ; i++)
        {
            if(issafe(i,col,board,n))
            {
                board[i][col] = 'Q';
                func(col+1,ans,board,n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n);
        //setting up the entire board
        // as we have n queens
        string s(n, '.');
        // initializing all the elements with .
        for(int i = 0 ; i < n ; i++)
        {
            board[i] = s;
        }
        // as we are iterating through the column we will have the column
        func(0,ans,board,n);
        return ans;
    }
};