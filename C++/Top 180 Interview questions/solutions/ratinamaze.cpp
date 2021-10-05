class Solution{
    
    void solve(int i, int j , int di[], int dj[], vector<string>& ans, string move
    , vector<vector<int>>& visited, vector<vector<int>>& m, int n)
    {
        if(i == n-1 && j == n-1)
        {
            ans.push_back(move);
            return ;
        }
        string str = "DLRU";
        for(int ind = 0; ind < 4 ; ind++)
        {
            int leftind = i + di[ind];
            int rightind = j + dj[ind];
            if(leftind>=0 && rightind>=0 && leftind <= n -1 && rightind<= n-1 && 
            visited[leftind][rightind]==0 && m[leftind][rightind]==1)
            {
                visited[i][j]=1;
                solve(leftind,rightind,di,dj,ans,move + str[ind],visited,m,n);
                visited[i][j]=0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        // we want the solution in the  lexpgraphical order
        vector<string> ans;
        // creating the visited array
        vector<vector<int>> visited(n, vector<int>(n,0));
        int di[4] = {1,0,0,-1};
        int dj[4] = {0,-1,1,0};
        if(m[0][0]==1) solve(0,0,di,dj,ans,"",visited,m,n);
        return ans;
    }
};