class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1st instance - even index
        // 2nd instance - odd index
        int low = 0;
        int high = nums.size() - 2;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid]==nums[mid^1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};	