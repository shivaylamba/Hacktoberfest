/*
Edit Distance
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.
*/
class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int m = str1.size() , n = str2.size();
        int dp[m+1][n+1];
        for(int i  =0  ; i<=m;i++){
            for(int j = 0;j<=n;j++){
                if (i == 0)    dp[i][j] = j;
            else if (j == 0)        dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])    dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j]
                    = 1
                      + min({dp[i][j - 1],
                            dp[i - 1][j], 
                            dp[i - 1][j - 1]});
            }
        }
        return dp[m][n];
    }
};