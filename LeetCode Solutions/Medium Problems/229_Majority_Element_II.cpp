/*
229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]
Example 3:
Input: nums = [1,2]
Output: [1,2]
 Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
Follow up: Could you solve the problem in linear time and in O(1) space?
*/
/*
  Approach - By Sliding Window
  Time Complexity O(n*log(n));
  Space Complexity O(1);
*/

/*
  Approach - hashing (map / unordered_map)
  Time Complexity O(n);
  Space Complexity O(n)->[for map/unordered_map] + O(n)->[ans array];
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> f;
        for(int x:nums){ f[x]++;}
        nums.clear();
        for(auto i :f){
            if(i.second > n/3){nums.push_back(i.first);}
        }
        return nums;
    }
};
//-------------------------------------------------------------------------------------------//
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> f;
        for(int x:nums){ f[x]++;}
        vector<int> ans ;
        for(auto i :f){
            if(i.second > nums.size()/3){ans.push_back(i.first);}
        }
        return ans;
    }
};
/*
  Approach - By Sorting and Counting
  Time Complexity O(n*log(n));
  Space Complexity O(n);
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        int cnt = 1;
        if(n ==1){
            return nums;
        }
         if(n == 2 && nums[0] != nums[1]){
            return nums;
        }
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            
            if(cnt > n / 3 && (result.empty() || nums[i] != result.back())) {
                result.push_back(nums[i]);
            }
        }
        
        return result;

    }
};