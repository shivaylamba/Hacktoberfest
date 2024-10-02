/*
260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:
Input: nums = [-1,0]
Output: [-1,0]
Example 3:
Input: nums = [0,1]
Output: [1,0]
Constraints:
2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/
/*
        BITWISE (FAST METHOD)
    Time Complexity O(n);
    Space Complexity O(1);
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
            int xor_result = 0;

    // Get the XOR of the two single numbers
    for (int num : nums) {
        xor_result ^= num;
    }

    // Find the rightmost set bit
    int rightmost_set_bit = 1;
    while ((rightmost_set_bit & xor_result) == 0) {
        rightmost_set_bit <<= 1;
    }

    // Partition the numbers into two groups based on the rightmost set bit
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightmost_set_bit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }

    return {num1, num2};
    }
};
/*
        HASHING METHOD
    Time Complexity O(n);
    Space Complexity O(n);
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        map<int,int> f;
        for(int x:nums){    f[x]++; }
        for(auto i:f){  if(i.second == 1)   ans.push_back(i.first); }
        return ans; 
    }
};