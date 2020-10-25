# Description Link: https://leetcode.com/problems/intersection-of-three-sorted-arrays/

class Solution:
    def arraysIntersection(self, arr1, arr2, arr3):
        ans = [val for val in arr1 if val in arr2 and val in arr3]
        return ans