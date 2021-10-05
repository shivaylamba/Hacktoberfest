class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxLen  = nums[0];
        int minLen = nums[0];
        int result = nums[0];
        for(int i = 1 ; i < len ; i++)
        {
            int tempmax = max(maxLen * nums[i] , max(minLen * nums[i], nums[i]));
            minLen = min(maxLen * nums[i] , min(minLen * nums[i], nums[i]));
            maxLen = tempmax;
            result = max(result,tempmax);
        }
        return result;
    }
};