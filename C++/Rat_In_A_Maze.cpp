#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    bool canGo(int newRow, int newCol, vector<vector<int>> visited, vector<vector<int>> m, int n){
        
        if((newRow<n && newRow>=0) && (newCol < n && newCol >= 0) && visited[newRow][newCol] == 0 && m[newRow][newCol] != 0){
            return true;
        }else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> m, int n, int row, int col, vector<vector<int>> visited, string output, vector<string> &ans){
        // base case 
        
        if(row == n-1 && col == n - 1){
            ans.push_back(output);
            return;
        }
        
        visited[row][col] = 1;
        
        // Go right
        int newRow = row;
        int newCol = col + 1;
        
        if(canGo(newRow, newCol, visited, m, n)){
            output.push_back('R');
            solve(m, n, newRow, newCol, visited, output, ans);
            output.pop_back();
        }
        
        // Go left
        newRow = row;
        newCol = col - 1;
        
        if(canGo(newRow, newCol, visited, m, n)){
            output.push_back('L');
            solve(m, n, newRow, newCol, visited, output, ans);
            output.pop_back();
        }
        
        //Go Up
        newRow = row - 1;
        newCol = col;
        
        if(canGo(newRow, newCol, visited, m, n)){
            output.push_back('U');
            solve(m, n, newRow, newCol, visited, output, ans);
            output.pop_back();
        }
        
        //Go Down
        newRow = row + 1;
        newCol = col;
        
        if(canGo(newRow, newCol, visited, m, n)){
            output.push_back('D');
            solve(m, n, newRow, newCol, visited, output, ans);
            output.pop_back();
        }
        
        visited[row][col] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited = m;
        
        string output;
        vector<string> ans;
        
        int row =0, col =0;
        
        if(m[row][col] == 0){
            return ans;
        }
        
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        solve(m, n, row, col, visited, output, ans);
        return ans;
    }
};


int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};


         Solution obj;

         vector<string> ans = obj.findPath(m, 4);
}