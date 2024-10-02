/*
974. Subarray Sums Divisible by K
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:
Input: nums = [5], k = 9
Output: 0
Constraints:
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
*/
/*
        PREFIX and HASHMAP
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int sum = 0, count=0;
        for(int i =0 ;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem<0) {    rem+=k;   }
            if(map.find(rem)!=map.end()){
                count+=map[rem];
                map[rem]+=1;
            }
            else{
                map[rem] = 1;
            }
        }
        return count;
    }
};
/*
        BRUTE FOREC (GET TLE)
    Time Complexity O(n^2)
    Space Complexity O(1)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count =0 ;
        for(int i =0 ; i<nums.size();i++){
            long long int sum = 0;
            for(int j = i;j<nums.size();j++){
                    sum+=nums[j];
                    if(sum%k==0) count++;
            }
        }
        return count ;
    }
};