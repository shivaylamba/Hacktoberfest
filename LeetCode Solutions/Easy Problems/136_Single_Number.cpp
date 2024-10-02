/*
136. Single Number
Given a non-empty array of integers nums, every element appears twice except for 
one. Find that single one.
You must implement a solution with a linear runtime complexity and use only 
constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1
Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which 
appears only once.
*/
// Optimized Approach 
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        if(nums.size()==1){
            return nums[0];
        }
        unordered_map<int,int> f;
        for(int x:nums){
            f[x]++;
        }
     for(auto i:f){
         if(i.second==1){
             ans = i.first;
         }
     }
     return ans;
    }
};
// Optimized Approach 
// Time Complexity O(n*log(n))
// Space Complexity O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=2)
        {
            if(nums[i] != nums[i-1])return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};