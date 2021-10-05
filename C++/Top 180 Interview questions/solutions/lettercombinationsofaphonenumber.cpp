class Solution {
public:
    void solve(int i, vector<string>& ans,vector<string>& maps, int n, string& str,string& digits)
    {
        if(i==n)
        {
            ans.push_back(str);
            return;
        }
        string temp = maps[digits[i]-'2'];
        int z = temp.size();
        for(int it = 0 ; it < z; it++)
        {
            str.push_back(temp[it]);
            solve(i+1,ans,maps,n,str,digits);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        vector<string> maps = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        string str;
        solve(0,ans,maps,n,str,digits);
        return ans;
    }
};