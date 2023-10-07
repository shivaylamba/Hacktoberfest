//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(int newx,int newy,int n,vector<vector<bool>> &visited,vector<vector<int>> &arr) {
        if((newx >= 0 and newx < n) and (newy >= 0 and newy <  n) and (visited[newx][newy] != 1) and 
        (arr[newx][newy] != 0))
        {
            return true;
        }
        else
        return false;
    }
    
    void solve(int x,int y,vector<vector<int>> &arr,int n,vector<string> &ans,
    vector<vector<bool>> &visited,string path)
    
    {
        //base case
        if(x == n-1 and y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // 4 movements 
        // down,left,right,up
        
        // down
        visited[x][y] = 1;
        if(isSafe(x+1,y,n,visited,arr)) {
             solve(x+1,y,arr,n,ans,visited,path+'D');
         }
        // left
        if(isSafe(x,y-1,n,visited,arr)) {
             solve(x,y-1,arr,n,ans,visited,path+'L');
         }
        // right
        if(isSafe(x,y+1,n,visited,arr)) {
             solve(x,y+1,arr,n,ans,visited,path+'R');
         }
        // up
        if(isSafe(x-1,y,n,visited,arr)) {
             solve(x-1,y,arr,n,ans,visited,path+'U');
        }
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        if(arr[0][0] == 0)
        return ans;
        solve(0,0,arr,n,ans,visited,path);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends