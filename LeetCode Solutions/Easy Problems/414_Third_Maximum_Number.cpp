/*
414. Third Maximum Number
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mx1 = LLONG_MIN, mx2 = LLONG_MIN, mx3 = LLONG_MIN;
        for (int num : nums) {
            if (num > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = num;
            } else if (num < mx1 && num > mx2) {
                mx3 = mx2;
                mx2 = num;
            } else if (num < mx2 && num > mx3) {
                mx3 = num;
            }
        }
        return mx3 == LLONG_MIN ? mx1 : mx3;
    }
};