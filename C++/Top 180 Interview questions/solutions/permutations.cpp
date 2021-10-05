class Solution {
public:
    void solve(int index, vector<vector<int>>& ans,vector<int>& nums)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index ; i < nums.size(); i++)
        {
           swap(nums[index], nums[i]);
           solve(index + 1, ans, nums);
           swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,ans,nums);
        return ans;
    }
};