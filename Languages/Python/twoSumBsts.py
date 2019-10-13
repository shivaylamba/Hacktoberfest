# Description Link: https://leetcode.com/problems/two-sum-bsts/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def inordertraverse(self, root, a):
        if root == None :
            return a
        a.append(root.val)
        a = self.inordertraverse (root.left, a)
        a = self.inordertraverse (root.right, a)
        return a
    def twoSumBSTs(self, root1, root2, target):
        a = self.inordertraverse (root1, [])
        b = self.inordertraverse (root2, [])
        for val in a:
            if target - val in b:
                return True
        return False