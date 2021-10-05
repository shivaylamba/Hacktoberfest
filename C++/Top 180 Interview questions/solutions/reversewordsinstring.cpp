class Solution {
public:
    string reverseWords(string s) {
    stringstream all(s);
        string word;
        string ans="";
        while(all >> word)
        {
            ans = word + (ans.size() ? " " : "") + ans;
        }
        return ans;
    }
};