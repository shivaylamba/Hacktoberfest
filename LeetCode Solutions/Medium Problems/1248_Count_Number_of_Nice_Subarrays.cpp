/*
1248. Count Number of Nice Subarrays
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
Constraints:
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/
/*
   OPTIMIZED APPROACH (Prefix / Sliding Window / Hash Table)
Time Complexity o(n);
Space Complexity o(n);
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};
/*
    NOT OPTIMIZED APPROACH (TIME LIMIT EXCEED ERROR)
Time Complexity o(n^2);
Space Complexity o(1);
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count  =0 ;
     for(int i = 0 ; i<nums.size();i++){
        int oddCount = 0 ;
        for(int j = i;j<nums.size();j++){
            if(nums[j]&1) oddCount++;
            if(oddCount==k) count++;
        }
     }   
     return count ;
    }
};