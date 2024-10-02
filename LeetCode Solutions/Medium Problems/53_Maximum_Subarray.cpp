/*
53. Maximum Subarray
Given an integer array nums, find the 
subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
 */
class Solution {
public:
// Time Complexity O(n)
// Space Complexity O(1)
        //kadanes's algo 
    int maxSubArray(vector<int>& nums) {
        int max_value = INT_MIN , max_end_here = 0;
        for(int x:nums){
            max_end_here+=x;
            // if(max_end_here > max_value)   max_value=max_end_here;
            max_value = max(max_value , max_end_here);
            if(max_end_here<0) max_end_here = 0;
        }
        return max_value;
    }
};