/*
Construct Tree from Inorder & Preorder
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
/*
Optimized Approach
Time Complexity: O(n^2), The worst case occurs when the tree is left-skewed. Example Preorder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
Auxiliary Space: O(n), The extra space used is due to the recursive call stack and the worst case occurs for a skewed tree.
*/
class Solution{
    private:
    int findPosition(int in[],int element,int st,int en ){
            for(int i = st ;i<=en;i++){
            if(element == in[i]){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd ,int n){
        if(index>=n || inorderStart > inorderEnd){
            return nullptr;
        }
        
        int element = pre[index++];  // At every interation index is increasing
        Node* root = new Node(element);
        int positionIn = findPosition(in,element ,inorderStart,inorderEnd);
    
    // Recursive Call 
    //  Left Call
    root->left = solve(in,pre,index,inorderStart,positionIn-1,n);
        
    // Right Call
    root->right = solve(in,pre,index,positionIn+1,inorderEnd,n);

return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0 ;//Pre order is NLR so First element is root .
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};
/*
 Most Optimized Approach -- But NOT WORK IN CASE OF DUPLICATION
Time Complexity: O(n)
Auxiliary Space: O(n), The extra space is used to store the elements in the map also due to recursive function call stack.
*/
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    void createMap(int in[],map<int,int> &nodeToIndex , int n){
           for(int i = 0 ; i<n;i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd ,
                                                int n,map<int,int> &nodeToIndex){
        if(index>=n || inorderStart > inorderEnd){
            return nullptr;
        }
        
        int element = pre[index++];  // At every interation index is increasing
        Node* root = new Node(element);
        int positionIn = nodeToIndex[element];
    
    // Recursive Call 
    //  Left Call
    root->left = solve(in,pre,index,inorderStart,positionIn-1,n,nodeToIndex);
        
    // Right Call
    root->right = solve(in,pre,index,positionIn+1,inorderEnd,n,nodeToIndex);

return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0 ;//Pre order is NLR so First element is root .
        map<int,int> nodeToIndex;
        createMap(in,nodeToIndex,n);
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};