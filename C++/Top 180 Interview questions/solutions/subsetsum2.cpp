class Solution {
public:
    void func(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        // we are pushing empty as well
        ans.push_back(ds);
        for(int i = ind ; i < nums.size(); i++)
        {
            
            // we also need to check condition for unique subset
            if(ind!=i && (nums[i]==nums[i-1])) continue;
            // there will be two scenerio we include the element or we dont' simple
            // first we inlcude
            ds.push_back(nums[i]);
            //next we call for next index
            func(i + 1, nums,ds,ans);
            // now we don't have too
            // so we can pop out
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        // it is vectors of vector
        sort(nums.begin(), nums.end());
        func(0,nums,ds,ans);
        return ans;
    }
};