/*
1296. Divide Array in Sets of K Consecutive Numbers
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
Return true if it is possible. Otherwise, return false.
Example 1:
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
Constraints:
1 <= k <= nums.length <= 105
1 <= nums[i] <= 109
 */
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k) return 0;
        map<int,int> map;
        for(int x:nums){  map[x]++;  }
    
        int n = nums.size();
        while(n--){
            for(auto i:map){
                int a = i.first;
                for(int j = a;j<a+k;j++){
                    if(map[j]==0) return 0;
                    map[j]--;
                    if(map[j]==0) map.erase(j);
                }
                break;
            }
        }
        return 1;
    }
};