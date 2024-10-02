/*
2248. Intersection of Multiple Arrays
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.
 

Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation: 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
 

Constraints:

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
All the values of nums[i] are unique.
*/
// Optimized Approach
// Time complexity O(n)
// Space complexity O(n)
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                f[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto i:f){
            if(i.second == nums.size()){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> sol;
        if(nums.size()==1){
            sort(nums[0].begin(),nums[0].end());
            return nums[0];
        }
        for(int i = 0; i < nums[0].size(); i++){
            for(int j = 1; j < nums.size(); j++){
                if(find(nums[j].begin(),nums[j].end(),nums[0][i])==nums[j].end()) break;
                if(j == nums.size() - 1) sol.push_back(nums[0][i]);
            }
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> hsh(1005,0),ans;
        for(auto&_nums:nums)
            for(int&x:_nums)
                hsh[x]++;
        for(int i=1; i<hsh.size(); i++)
            if(hsh[i]==nums.size()) ans.push_back(i);
        return ans;   
    }
};