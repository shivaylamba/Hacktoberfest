class Solution {
public:
    string longestPalindrome(string s) {
     if(s.size()==0) return "";
        int i = 0, j = 0;
        int n = s.size();
        // we will only need half of the P
        bool P[n][n];
        memset(P,false,sizeof(P));
        for(int x = 0;x<n;x++){
            P[x][x]=true;
            if(x==n-1) break;
            P[x][x+1] = (s[x]==s[x+1]);
        }
        //dp 
        //get maxstr result
        int max = 0;
        string maxstr = "";
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                P[i][j] = (P[i+1][j-1] && s[i]==s[j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // for checking the maximum substring we need to iterate in the entire
                //  right matrix
                if(P[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};