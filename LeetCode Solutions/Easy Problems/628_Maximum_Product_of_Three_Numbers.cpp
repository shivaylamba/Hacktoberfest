/*
628. Maximum Product of Three Numbers
Given an integer array nums, find three numbers whose product is maximum and 
return the maximum product.
Example 1:
Input: nums = [1,2,3]
Output: 6
Example 2:
Input: nums = [1,2,3,4]
Output: 24
Example 3:
Input: nums = [-1,-2,-3]
Output: -
Constraints:
3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/
 
// Most Optimized Approach
 // Solution-1
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
  int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] <= min1){
				min2 = min1;
				min1 = nums[i];
			} 
			else if(nums[i] <= min2){
				min2 = nums[i];
			}
			if(nums[i] >= max1){ 
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			} 
			else if(nums[i] >= max2){
				max3 = max2;
				max2 = nums[i];
			} 
			else if(nums[i] >= max3){
				max3 = nums[i];
			}
		}
		return max(min1 * min2 * max1, max1 * max2 * max3);
	}
};
// Least Optimized Approach
 // Solution-2
// Time Complexity O(n*log(n))
// Space Complexity O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3){return -1;}
        int n =nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
};