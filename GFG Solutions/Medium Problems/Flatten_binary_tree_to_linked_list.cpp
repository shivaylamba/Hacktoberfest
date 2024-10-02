/*
Flatten binary tree to linked list
Given the root of a binary tree, flatten the tree into a "lLinked list":
The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:
Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linked list without using any auxiliary space.
Note: The driver code prints the in-order traversal of the flattened binary tree.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints :
1<=n<=10^5
*/
//User function Template for C++
/*
    MORRIS TRAVERSAL
Time Complexity O(n)
Space Complexity O(1)
*/
class Solution
{
    public:
    Node* findPredcessor(Node* curr){
        Node* temp = curr;
        temp = temp->left;
        while(temp->right) temp = temp->right;
        
        return temp;
    }
    void flatten(Node *&root)
    {
        //code here
        Node*curr = root;
        while(curr){
            if(curr->left){
                Node* predcessor = findPredcessor(curr);
                
                predcessor->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
/*
  OPTIMAL APPROACH USING STACK
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        if(!root) return ;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* topNode = st.top();
            st.pop();
            if(topNode->right) st.push(topNode->right);
            if(topNode->left) st.push(topNode->left);
            if(!st.empty()){
                topNode->right = st.top();
            }
            topNode->left = nullptr;
        }
    }
};
/*
    USING RECURSION
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution
{
    public:
    void dfs(Node*&root,Node*&prev){
        if(!root) return ;
        dfs(root->right,prev);dfs(root->left,prev);
        root->right= prev;
        root->left = nullptr;
        prev = root;
    }
    void flatten(Node *root)
    {
        //code here
        Node* prev = nullptr;
        dfs(root,prev);
    }
};