class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int t[n+1][m+1];
        for(int i = 0 ; i<n+1 ; i++)
        {
            for(int j = 0; j<m+1 ;j++)
            {
               if(i==0 || j==0)
                   t[i][j]=0;
            }
            // this is the alternative of the base condition
        }
        for(int i = 1 ; i<n+1 ; i++)
        {
            for(int j = 1; j<m+1 ;j++)
            {
                if(text1[i-1]==text2[j-1])
                    t[i][j]=1+ t[i-1][j-1];
                // dont forget to do +1 here
                else
                    t[i][j]= max(t[i-1][j],t[i][j-1]);
            }
        }
        string s;
        int i = n;
        int j = m;
        while(i>0 && j > 0)
        {
            if(text1[i-1]==text2[j-1])
            {
                s+=text1[i-1];
                i--;
                j--;
            }
            else 
            {    
                if(t[i][j-1] > t[i-1][j])
                {
                    s+=text2[j-1];
                    j--;
                }
                else
                {
                    s+=text1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            s+=text1[i-1];
            i--;
        }
        while(j>0)
        {
            s+=text2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // length of shortest common supersequence will be M + N - LCS;
        return longestCommonSubsequence(str1,str2);
        
    }
};
