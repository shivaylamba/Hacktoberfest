class BSTIterator {
private:
    TreeNode *current = NULL; 
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
         // initialize the current pointer
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while(current){
            s.push(current);
            current = current->left;
        }
        if(s.empty()){
            return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        s.pop();
        current = node->right;
        return node->val;
    }
};