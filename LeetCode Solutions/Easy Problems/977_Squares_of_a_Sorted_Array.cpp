/*
977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
// Least Optimized Approach
// Time Complexity O(n*log(n))
// Space Complexity O(n)
        // for(int i=0;i<nums.size();i++){
        //     nums[i]=pow(nums[i],2);
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        
// Optimized Approach
// Time Complexity O(n)
// Space Complexity O(n)
// Two-Pointer Approach
        int i=0,j=nums.size()-1;
        int k=j;
        vector<int> ans(nums.size());
        while(i<=j ){
            if(abs(nums[i])<abs(nums[j])){
                   ans[k]= pow(nums[j--],2);
            }
            else{
               ans[k]= pow(nums[i++],2);
            }
            k--;
        }
        return ans;
    }
};