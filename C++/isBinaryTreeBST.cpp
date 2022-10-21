#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * left, * right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
    public:
        bool isValidBST(Node * root) {
            return solve(root, INT_MIN, INT_MAX);
        }

    bool solve(Node * root, int minVal, int maxVal) {
        if (root == NULL) return true;
        if (root -> data >= maxVal || root -> data <= minVal) return false;
        return solve(root -> left, minVal, root -> data) && solve(root -> right, 
        root -> data, maxVal);
    }
};
int main() {
    Node * root = new Node(7);
    root -> left = new Node(5);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(6);
    root -> right = new Node(10);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(15);
    Solution ob;
    bool ans = ob.isValidBST(root);
    if (ans == true) {
        cout << "Valid BST";
    } else {
        cout << "Invalid BST";
    }
    return 0;
}