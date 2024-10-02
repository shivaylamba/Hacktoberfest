/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
Constraints:
1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6

=>Intuition
Easy Problem using C++ beginner Friendly Solution

=>Approach
1-let a Variable name sum = nums[i] // store the value of 0th index;
2-loop through the array.
3-add the sum value on the current indexed array element.
4-reinitailized sum = nums[i] // current element value after adding the sum;
=>Complexity
Time complexity: O(n)O(n)O(n)
Space complexity: O(1)O(1)O(1)
*/
class Solution {
public:
// Optimized Method 
//  Time Complexity O(n);
//  Space Complexity O(1);
    vector<int> runningSum(vector<int>& nums) {
        int sum =0;
        sum = nums[0];
        for(int i =1;i<nums.size();i++){
           nums[i]+=sum;
           sum=nums[i];
        }
        return nums;
    }
// MOST Optimized Method 
//  Time Complexity O(n);
//  Space Complexity O(1);
        vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){

            nums[i]+=nums[i-1];

        }

        return nums;
    }
};