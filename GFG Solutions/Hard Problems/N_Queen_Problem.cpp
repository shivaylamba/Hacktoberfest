/*
N-Queen Problem
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].
Examples
Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: 4
Output: [[2 4 1 3 ],[3 1 4 2 ]]
Explaination: These are the 2 possible solutions.
Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 
Constraints:
1 ≤ n ≤ 10
*/
// User function Template for C++

class Solution{
public:
    vector<vector<int>> res;
    bool check( int x, int y, int n, vector<vector<int>> &chessBoard ){
        int i, j;
        i = x-1; j = y;
        while ( i >= 0 ) if ( chessBoard[i--][j] == 1 ) return false;
        i = x+1; j = y;
        while ( i < n ) if ( chessBoard[i++][j] == 1 ) return false;
        i = x; j = y-1;
        while ( j >= 0 ) if ( chessBoard[i][j--] == 1 ) return false;
        i = x-1; j = y-1;
        while ( i >= 0 && j >= 0 ) if ( chessBoard[i--][j--] == 1 ) return false;
        i = x+1; j = y-1;
        while ( i < n && j >= 0 ) if ( chessBoard[i++][j--] == 1 ) return false;
        return true;
    }
    void rec( int j, int n, vector<int> &pos, vector<vector<int>> &chessBoard ){
        if ( j == n ){
            res.push_back(pos);
            return;
        }
        for ( int i = 0; i<n; i++ ){
            if ( check(i, j, n, chessBoard) ) {
                pos.push_back(i+1);
                chessBoard[i][j] = 1;
                rec(j+1, n, pos, chessBoard);
                chessBoard[i][j] = 0;
                pos.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> chessBoard(n+1, vector<int>(n+1, 0));
        vector<int> pos; rec(0, n, pos, chessBoard);
        return res;
    }
};