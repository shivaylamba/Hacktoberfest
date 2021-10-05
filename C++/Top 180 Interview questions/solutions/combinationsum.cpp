class Solution {
public:
    void func(int ind, vector<int>& cand, int target, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(ind==cand.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        // now we will choose the elements
        if(cand[ind]<=target)
        {
            ds.push_back(cand[ind]);
            func(ind,cand,target-cand[ind],ds,ans);
            ds.pop_back();
        }
        func(ind+1, cand,target,ds,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,cand,target,ds,ans);
        return ans;
    }
};