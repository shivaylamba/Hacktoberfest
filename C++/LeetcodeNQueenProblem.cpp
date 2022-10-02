class Solution {
    vector<vector<string>> ans;
public:
    
    bool isSafe(vector<string> &board, int row, int col)
    {
        int n = board.size() ;
        if(row<0 || col <0 || row >= n || col >= n)
            return false ;
        for(int i = row ;i >= 0 ;i-- ){
            if(board[i][col] == 'Q')
                return false ;
        }
        for(int i =row  , j= col ; i>=0 and j>=0 ; --i , --j){
            if(board[i][j] == 'Q')
                return false ;
        }
        for(int i =row ,j =col ; i>=0 and j<n ; ++j ,--i ){
            if(board[i][j] == 'Q')
                return false ;
        }
        return true ;
    }
    
    void dfs(vector<string> &board, int row)
    {
        if(row == board.size())
        {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            if(isSafe(board, row, i))
            {
                board[row][i] = 'Q';
                dfs(board, row+1);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        if(n <= 0)  return ans;
        dfs(board, 0);
        return ans;
        
    }
};
