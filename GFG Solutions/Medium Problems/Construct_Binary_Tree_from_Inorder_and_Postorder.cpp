/*
Construct Binary Tree from Inorder and Postorder
Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Example 1:

Input:
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 
1 2 4 8 5 3 6 7
Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8
Example 2:

Input:
n = 5
in[] = {9, 5, 2, 3, 4}
post[] = {5, 9, 3, 4, 2}
Output: 
2 9 5 4 3
Explanation:  
The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 103
1 <= in[i], post[i] <= 106
*/
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
/*
 Most Optimized Approach -- But NOT WORK IN CASE OF DUPLICATION
Time Complexity: O(n*log(n))
Auxiliary Space: O(n), The extra space is used to store the elements in the map also due to recursive function call stack.
*/

/*
Optimized Approach
Time Complexity: O(n^2), The worst case occurs when the tree is left-skewed. Example PostORder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
Auxiliary Space: O(n), The extra space used is due to the recursive call stack and the worst case occurs for a skewed tree.
*/
class Solution
{
    private:
    int findPosition(int in[],int element ,int inorderStart,int inorderEnd){
        for(int i =inorderStart ; i<= inorderEnd;i++){
            if(in[i] == element) return i;
        }
        return -1;
    }
    Node* solve(int in[],int post[],int &postIndex , int inorderStart,int inorderEnd , int n){
        // Base Case
        if(postIndex < 0|| inorderStart> inorderEnd){
            return nullptr;
        }
        int element = post[postIndex--]; // At every interation index is decreasing
        Node* root = new Node(element);
        int positionIn = findPosition(in,element,inorderStart,inorderEnd);

        //  Following right part First then then last part because LRN postOrder Format
        // Recursive Call         
        // Right Call 
        root->right = solve(in,post,postIndex,positionIn+1,inorderEnd,n);
    //  Left Call
        root->left = solve(in,post,postIndex,inorderStart,positionIn-1,n);

        
    return root;
    }
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int postIndex = n-1;//Post order is LRN so last element is root .
        Node* ans = solve(in,post,postIndex,0,n-1,n);
        return ans;
        // Your code here
    }
};
