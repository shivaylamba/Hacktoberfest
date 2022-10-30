/*
PostOrder Traversal
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 

Sample Output 1:
400 50 20 30 40 10
*/

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return;
    }
    
    for(int i = 0; i < root -> children.size() ; i++) {
        printPostOrder(root -> children[i]);
    }
    
    cout << root -> data << " "; 
}
