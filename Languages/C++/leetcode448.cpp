/*
	Leetcode Problem solution 
	448. Find All Numbers Disappeared in an Array
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i =0; i<nums.size(); i++){
            int in = abs(nums[i])-1;
            
            if(nums[in] > 0)
                nums[in] = -nums[in];
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};
