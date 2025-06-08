# Problem: Maximum Subarray (LeetCode 53)
# Time Complexity: O(n)
# Space Complexity: O(1)

def maxSubArray(nums):
    max_sum = nums[0]  # Max subarray sum found so far
    curr_sum = nums[0] # Current subarray sum

    for i in range(1, len(nums)):
        curr_sum = max(nums[i], curr_sum + nums[i])  # Start new or continue subarray
        max_sum = max(max_sum, curr_sum)             # Update max sum

    return max_sum
