/*
287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
Constraints:
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/
// Approach - By using the Slow and fast
//  Time Complexity O(n)
//  Space Complexity O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr = nums;

        while(arr[0] != arr[arr[0]])
            swap(arr[0],arr[arr[0]]);
        return arr[0];
    }
};
// Approach - Hashing -> map/unordered_map
//  Time Complexity O(n)
//  Space Complexity O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int x:nums){f[x]++;}
        for(auto i:f){
            if(i.second>1){
                return i.first;
            }
        }
        return -1;
    }
};
// Approach - By Sorting with inbuild Function
//  Time Complexity O(n*log(n))
//  Space Complexity O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0 ;i<nums.size();i++){
          if(nums[i]==nums[i+1]){
            return nums[i];
          }
        }
        return -1;
    }
};