/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because 
there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/
// Most Optimized Approach
// Time Complexity O(n);
// Space Complexirty O(1);
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre = 0 , suff = 0;
        for(int i :nums){  pre+=i; }
        for(int i = 0 ;i<nums.size();i++){
             pre -=nums[i];
             if(pre==suff) return i;
            suff +=nums[i];
        }
        return -1;
    }
};
// Most Optimized Approach
// Time Complexity O(n);
// Space Complexirty O(1);
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0 ;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
        }
        int prefix = 0 ;
        for(int i=0; i<nums.size(); i++){
            if(i == 0)
                prefix = 0 ;
            else 
                prefix += nums[i-1] ;
            int rest = sum - prefix - nums[i] ;
            if(rest == prefix)
                return i ;
        }
        return -1 ;
    }
};

// Not Optimized Approach
// Time Complexity O(n^2);
// Space Complexirty O(1);
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int ls= 0 , rs = 0;
            for(int j=0;j<i;j++){
                ls+=nums[j];
            }
            for(int j=i+1;j<nums.size();j++){
                rs+=nums[j];
            }
            if(ls==rs){return i;}
        }
            return -1;
    }
};

