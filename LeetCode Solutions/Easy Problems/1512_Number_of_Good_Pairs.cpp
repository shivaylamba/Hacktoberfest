/*
1512. Number of Good Pairs
Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.
Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:
Input: nums = [1,2,3]
Output: 0
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
/*
    OPTMIZED APPROACH HASHMAP
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int count = 0;
        for(int x:nums){
            if(map[x]){ count+=map[x];    }
            map[x]++;
        }
        return count;
    }
};
//---------------------------------Shorter Method-------------------------------------------------//
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> cnt;
        int ans=0;
        for(int x:nums){
            ans+=cnt[x]++;
        }
        return ans;
    }
};