class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size() ;
        for(int i = 1  ; i < n ; i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
        }
    
};