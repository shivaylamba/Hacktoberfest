#[derive(Debug)]
struct TreeNode {
    val: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

impl TreeNode {
    fn new(val: i32) -> Self {
        TreeNode { val, left: None, right: None }
    }
}

fn dfs(root: &Option<Box<TreeNode>>) {
    if let Some(node) = root {
        println!("{}", node.val);  // Process the current node
        dfs(&node.left);
        dfs(&node.right);
    }
}

use std::collections::VecDeque;

fn bfs(root: &Option<Box<TreeNode>>) {
    let mut queue = VecDeque::new();
    if let Some(node) = root {
        queue.push_back(node);
    }

    while let Some(node) = queue.pop_front() {
        println!("{}", node.val);  // Process the current node
        if let Some(ref left) = node.left {
            queue.push_back(left);
        }
        if let Some(ref right) = node.right {
            queue.push_back(right);
        }
    }
}

impl TreeNode {
    fn insert(&mut self, val: i32) {
        if val < self.val {
            if let Some(ref mut left) = self.left {
                left.insert(val);
            } else {
                self.left = Some(Box::new(TreeNode::new(val)));
            }
        } else {
            if let Some(ref mut right) = self.right {
                right.insert(val);
            } else {
                self.right = Some(Box::new(TreeNode::new(val)));
            }
        }
    }
}

fn find_lca(root: &Option<Box<TreeNode>>, p: i32, q: i32) -> Option<i32> {
    if let Some(node) = root {
        if node.val == p || node.val == q {
            return Some(node.val);
        }

        let left = find_lca(&node.left, p, q);
        let right = find_lca(&node.right, p, q);

        if left.is_some() && right.is_some() {
            return Some(node.val);
        }

        return left.or(right);
    }
    None
}

fn tree_height(root: &Option<Box<TreeNode>>) -> i32 {
    if let Some(node) = root {
        let left_height = tree_height(&node.left);
        let right_height = tree_height(&node.right);
        return 1 + left_height.max(right_height);
    }
    0
}

fn main() {
    println!("Hello, world!");
}
