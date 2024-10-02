/*
442. Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:
Input: nums = [1,1,2]
Output: [1]
Example 3:
Input: nums = [1]
Output: []
Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/
/*
    Approach - (hashing) - >Unordered_map/map
    Time Complexity O(n)
    Spac Complexity O(n)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int x:nums){f[x]++;}
        nums.clear();
        for(auto i:f){
            if(i.second>1){ nums.push_back(i.first);}
        }
        return nums;
    }
};

/*
    Approach - Sorting
    Time Complexity O(n*log(n))
    Spac Complexity O(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
                vector <int> ans;
    for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;

            if(nums[index]<0){  // the number which become < 0 in else condition is seen again
                ans.push_back(abs(nums[i]));
            }
            nums[index]=nums[index]*-1;
        }
        return ans;
    }
};
/*
    Approach - Sorting
    Time Complexity O(n*log(n))
    Spac Complexity O(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
                vector <int> ans;
    sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
               
            }          
        }
        return ans;
    }
};