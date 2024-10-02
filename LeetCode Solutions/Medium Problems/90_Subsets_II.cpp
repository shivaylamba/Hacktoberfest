/*
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
class Solution {
public:
   void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx){
        ans.push_back(curr);                             
        for(int i=idx;i<nums.size();i++){                      
            if(i>idx &&  nums[i]==nums[i-1]) 
            continue;                                          
            curr.push_back(nums[i]);                           
            helper(nums,ans,curr,i+1); 
            curr.pop_back();                                  
        }
   }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> curr; 
        sort(nums.begin(),nums.end()); 
                     
        helper(nums,ans,curr,0);                      
        return ans; 
      } 
    
};