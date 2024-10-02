/*
137. Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,3,2]
Output: 3
Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/
/*
    BITWISE
    Time Complexity O(n)
    space Complexity O(n)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<32; i++) {
            int count = 0;
            for(int i=0; i<n; i++) {
                count += (nums[i] & 1);
                nums[i] >>= 1;
            }
            if(count % 3) ans |= (1 << i);
        }
        return ans;
    }
};
/*
    HASHING
    Time Complexity O(n)
    space Complexity O(n)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> f;
        int ans = -1;
        for(int x:nums){    f[x]++; }
        for(auto i:f){  if(i.second == 1){ ans = i.first ; break;}}
        return ans; 
    }
};