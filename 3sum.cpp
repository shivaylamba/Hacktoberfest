class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i =0;
        int sum = 0;
        int j=0;
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> two;
        while(j<n)
        {
            sum = sum+nums[j];
            ans.push_back(nums[j]);
            if((j-i+1)<3)
            {
                j++;
            }
            else if((j-i+1)==3)
            {
                if(sum==0)
                {
                    two.push_back(ans);
                }
                ans.erase(ans.begin());
                sum = sum-nums[i];
                i++;
                j++;
            }
        }
        return two;
    }
};
