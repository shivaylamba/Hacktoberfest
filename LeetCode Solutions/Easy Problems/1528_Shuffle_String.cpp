/*
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character 
at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.
Example 1:
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
Constraints:
s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.
*/
class Solution {
public:
//  Most Optimized Approach
//  Time Complexity O(n)
//  Space Complexity O(1)
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        for(int i=0 ; i<s.length(); i++){
            str[indices[i]] = s[i];
        }
        return str;
    }
//  Optimized Approach
//  Time Complexity O(n)
//  Space Complexity O(n)
    string restoreString(string s, vector<int>& indices) {
     vector<int> ans(indices.size(),0);
     for(int i=0;i<indices.size();i++){
         ans[indices[i]]=s[i]-'a';
     }  
     string str="";
     for(int i=0;i<ans.size();i++){
         str.push_back('a'+ans[i]);
     }
     return str;
    }
};