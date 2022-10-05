class Solution {
public:
    TreeNode* preorder(TreeNode* root,int value,int depth){
        if(root == NULL)    return NULL;
        if(depth == 2){
            TreeNode* leftNode = new TreeNode(value);
            TreeNode* rightNode = new TreeNode(value);
            
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            
            return root;
            
        }
        root->left = preorder(root->left,value,depth-1);
        root->right = preorder(root->right,value,depth-1);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* newNode =  new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        
        return preorder(root,v,d);
    }
};
