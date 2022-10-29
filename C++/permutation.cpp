class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&v,int i)
    {
        if(i>=nums.size())
        {
            v.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            solve(nums,v,i+1);
            swap(nums[i],nums[j]);
        }
          
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>v;
        int i=0;
        solve(nums,v,i);
        return v;
        
    }
};