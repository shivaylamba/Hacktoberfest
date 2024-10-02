/*
Form a palindrome
Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

Examples :

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
Input: str = "aa"
Output: 0
Explanation: "aa" is already a palindrome.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ |str| ≤ 500
str contains only lowercase alphabets.
*/
//User function template for C++

class Solution{
  public:
    int LCS(int n,string s1,string s2){
        int dp[n+1][n+1];
        //base case
        //CodeGenius
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        //recursive case
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int countMin(string str){
        string rev=str;
        int n=str.size();
        reverse(rev.begin(),rev.end());
        return n-LCS(n,str,rev);
    }
    
};