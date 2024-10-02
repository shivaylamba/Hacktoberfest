/*
Merge two BST 's
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O(m+n)
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes ≤ 105
*/
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> arr1,arr2;
    void inorder(Node *root,bool flag){
        if(!root){
            return ;
        }
        inorder(root->left,flag);
        if(!flag){
            arr1.push_back(root->data);
        }
        else{
            arr2.push_back(root->data);
        }
        inorder(root->right,flag);

    }
    vector<int> merge(Node *root1, Node *root2) {
        // codeGenius
        inorder(root1,0);
        inorder(root2,1);
        vector<int> ans;
        int i=0,j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]>arr2[j]){
                ans.push_back(arr2[j++]);
            }
            else{
                ans.push_back(arr1[i++]);
            }
        }
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }

        return ans;

    }
};