/*
Wildcard Pattern Matching
Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.
The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).
Note: The matching should cover the entire str (not partial str).
Examples:
Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
Constraints:
1 <= length of(str, pattern) <= 200
*/
class Solution {
  public:
    /*You are required to complete this method*/
    vector<vector<int>> dp;
    int finding(string &s,int n,string &p,int m){
        if(n<0 && m<0) return 1;
        if(m<0) return 0;
        if(n<0){
            while(m>=0){
                if(p[m]!='*') return 0;
                m--;
            }
            return 1;
        }
        if(dp[n][m] == -1){
         if (p[m] == '*') {
            return dp[n][m] = finding(s, n - 1,p, m)
                              || finding(s, n,p, m - 1);
        }
        else {
            if (p[m] != s[n] && p[m] != '?')
                return dp[n][m] = 0;
            else
                return dp[n][m]
                       = finding(s, n - 1,p, m - 1);
        }
    }
     return dp[n][m];   
    }
    int wildCard(string pattern, string str) {
        // code here
        dp.clear();
        dp.resize(str.size()+1,vector<int>(pattern.size()+1,-1));
        return dp[str.size()][pattern.size()] = finding(str,str.size()-1,pattern,pattern.size()-1);
    }
};