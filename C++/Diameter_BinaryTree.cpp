#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode(){

        delete left;
        delete right;
    }
};
    
int helper(TreeNode *root){

    if(!root) return 0;
        
    return 1 + max( helper(root -> right), helper(root -> left) );
}

// Function to find Diameter of Binary Tree
int diameterOfBinaryTree(TreeNode* root) {
        
    if(!root) return 0;
       
    int left = helper(root -> left);
    int right = helper(root -> right);
    return max( left + right, max(diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right))); 
    
}  

// Function to take tree input level wise
TreeNode* takeInputLevelWise(){
    
    cout<<"Enter Root Data: ";
    int rootData;
    cin>>rootData;
    if(rootData == -1) return NULL;

    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()){
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter Left of "<<front->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            TreeNode *leftChild = new TreeNode(leftData);
            pendingNodes.push(leftChild);
            front -> left = leftChild;
        }

        cout<<"Enter Right of "<<front->data<<": ";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            TreeNode *rightChild = new TreeNode(rightData);
            front -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

// Binary Tree : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){

    TreeNode *root = takeInputLevelWise();
    cout<<endl<<"Diameter of Tree is: "<<diameterOfBinaryTree(root)<<endl;

    delete root;
    return 0;
}   
