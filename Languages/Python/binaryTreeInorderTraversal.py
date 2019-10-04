class binaryTreeInorderTraversal:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res,stack = [], [(root,False)]
        while stack:
            cur,visited = stack.pop()
            if cur:
                if visited:
                    res.append(cur.val)
                else:
                    stack.append((cur.right,False))
                    stack.append((cur,True))
                    stack.append((cur.left, False))
        return res
