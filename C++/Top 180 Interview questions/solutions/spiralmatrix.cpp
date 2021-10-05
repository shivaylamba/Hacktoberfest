class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
         vector<int> v;
        int k=0;//starting row  
        int l=0;// starting column    
        int m=a.size();// ending row
        int n=a[0].size();// ending column
        while(k<m && l<n){
        for(int i=l; i<n;i++)
            v.push_back(a[k][i]);
        k++;
        for(int i=k ; i<m; i++)
            v.push_back(a[i][n-1]);
        n--;
        if(k<m){
            for(int i=n-1; i>=l; i--)
                v.push_back(a[m-1][i]);
        m--;
        }
        if(l<n){
            for(int i=m-1;i>=k;i--)
                v.push_back(a[i][l]);
        l++;
        }
            
        }
        return v;
    }
};