    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode curr = root;
        while (curr != null) {
            res.add(curr.val);
            
            if (curr.left != null) {
                TreeNode node1 = getRightMostNodeOfLeftSubtree(curr);
                node1.right = curr.right;
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        return res;
    }
    
    private TreeNode getRightMostNodeOfLeftSubtree(TreeNode node) {
        TreeNode curr = node.left;
        while (curr.right != null) {
            curr = curr.right;
        }
        return curr;
    }
