
/*
485. Max Consecutive Ones
Easy

3513

411

Add to List

Share
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1. 

*/

// solution
  


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxim=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==1){
                count++;
            }
        else{
            count=0;
            }
            maxim= max(maxim,count);
        }
            return maxim;
    }
};

