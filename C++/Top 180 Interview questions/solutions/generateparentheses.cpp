class Solution {
public:
    vector<string> ans;
    void func(int start, int end , string output)
    {
        if(start==0 && end == 0)
        {
        ans.push_back(output);
            return;
        }
        if(start > 0)
            func(start-1,end,output + '(');
        if(end > start)
            func(start,end-1,output + ')');
    }
    vector<string> generateParenthesis(int n) {
     int start = n;
        int end = n;
        string output;
        func(start,end,output);
     return ans;   
    }
};