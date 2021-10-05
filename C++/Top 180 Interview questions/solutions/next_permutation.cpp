class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // code after watching the video
      // following the particular algorithm
        
        int n = nums.size();
        int k;
        int l;
        for(k = n -2 ; k>=0 ; k--)
        {
            if(nums[k] < nums[k+1])
                break;
        }
        if(k<0)
        {
            // this means there is no break point and we are at the last permutation
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(l = n - 1 ; l> k; l--)
            {
                // we need to only move uptil the last break point only
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};