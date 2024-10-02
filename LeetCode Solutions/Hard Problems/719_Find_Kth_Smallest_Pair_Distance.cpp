/*
719. Find K-th Smallest Pair Distance
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:
Input: nums = [1,1,1], k = 2
Output: 0
Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
Constraints:
n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2
*/
#include <vector>
#include <algorithm>
class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
private:
    int countPairs(const std::vector<int>& nums, int distance) {
        int count = 0, left = 0;
        for (int right = 1; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > distance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};