#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<TreeNode*> constructBST(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        cout << "start=" << start << " end=" << end << endl;
        trees.push_back(NULL);
    }
    for (int i = start;i <= end;i++) {
        vector<TreeNode*> leftTrees = constructBST(start, i - 1);
        vector<TreeNode*> rightTrees = constructBST(i + 1, end);
        for (int j = 0;j < leftTrees.size();j++) {
            TreeNode* left = leftTrees[j];
            for (int k = 0;k < rightTrees.size();k++) {
                TreeNode* right = rightTrees[k];
                TreeNode* node = new TreeNode(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<TreeNode*> trees = constructBST(1, 3);
    for (int i = 0;i < trees.size();i++) {
        preOrder(trees[i]);
        cout << endl;
    }
}
