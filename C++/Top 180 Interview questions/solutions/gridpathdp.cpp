class Solution {
public:
    int func(int i , int j, int m, int n,int t[][101])
    {
        if(t[i][j]!=-1)
            return t[i][j];
        if(i==m-1 || j==n-1) 
        {
            return t[i][j]=1;
        }
        if(i>=m || j>=n) return t[i][j]=0;
        else return t[i][j]=(func(i+1,j,m,n,t) + func(i,j+1,m,n,t));
    }
    int uniquePaths(int m, int n) {
        int t[101][101];
        memset(t,-1,sizeof(t));
       return func(0,0,m,n,t); 
    }
};