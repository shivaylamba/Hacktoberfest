# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

# Notice that the solution set must not contain duplicate triplets.

 

# Example 1:

# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation: 
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
# Notice that the order of the output and the order of the triplets does not matter.
# Example 2:

# Input: nums = [0,1,1]
# Output: []
# Explanation: The only possible triplet does not sum up to 0.
# Example 3:

# Input: nums = [0,0,0]
# Output: [[0,0,0]]
# Explanation: The only possible triplet sums up to 0.

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        triplet_count = 0
        final_list = set()

        for i in range(0, len(nums)-1):
            s = set()
            temp_list = []

            temp_list.append(nums[i])
            currk = 0 - nums[i]

            for j in range(i+1, len(nums)):
                if (currk - nums[j]) in s:
                    triplet_count += 1 

                    temp_list.append(nums[j])
                    temp_list.append(currk-nums[j])

                    final_list.add((tuple(sorted(temp_list))))
                    temp_list.pop(2)
                    temp_list.pop(1)
                s.add(nums[j])
        final_list = sorted(final_list)
        return([list(x) for x in final_list])
