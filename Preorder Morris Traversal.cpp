#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;

    TreeNode* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            res.push_back(curr->val);
            if (curr->right) s.push(curr->right);
            curr = curr->left;
        }
        if (!s.empty()) {
            curr = s.top();
            s.pop();
        }
    }
    return res;
}

int main() {
    // Create a sample binary tree.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform preorder traversal and print the result.
    vector<int> result = preorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
