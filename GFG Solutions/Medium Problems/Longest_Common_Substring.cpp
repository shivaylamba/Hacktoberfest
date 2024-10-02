/*
Longest Common Substring
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.
Examples:
Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.
*/
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        vector<vector<int>> dp(str1.size()+1,vector<int> (str2.size()+1, 0));
        int res = 0 ;
        for(int i  =1  ;i<=str1.size();i++){
            for(int j =1 ;j<=str2.size();j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(res<dp[i][j]) res = dp[i][j];
                }
            }
        }
        return res;
    }
};