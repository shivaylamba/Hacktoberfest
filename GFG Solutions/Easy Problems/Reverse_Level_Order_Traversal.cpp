/*
Reverse Level Order Traversal
Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 
3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 
40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10
Your Task: 
You don't need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 104
*/
/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*
----------------- APPROACH-1 LEVEL ORDER TRAVERSAL (STACK & QUEUE)----------------
   T    Time Complexity: O(n), where n is the number of nodes in the binary tree. 
        Auxiliary Space: O(n), for stack and queue.
*/
vector<int> reverseLevelOrder(TreeNode* root) {
    vector<int> result;
    if (root == nullptr)
        return result;

    queue<TreeNode*> q;
    stack<TreeNode*> s;

    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Push the node onto the stack
        s.push(node);

        // Enqueue right child first if exists
        if (node->right)
            q.push(node->right);

        // Enqueue left child if exists
        if (node->left)
            q.push(node->left);
    }

    // Pop nodes from stack and collect them in the result vector
    while (!s.empty()) {
        result.push_back(s.top()->val);
        s.pop();
    }

    return result;
}
/*
--------------------------- APPROACH-2 BRUTE FORCE-----------------------------------
    Time Complexity O(n)
    Time Complexity O(n) , n =number of nodes
*/
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
            vector<int> res;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0  ;i<n;i++){
            Node* front = q.front();
            q.pop();
            if(front) res.push_back(front->data);
            
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        ans.push_back(res);
        res.clear();
    }
    res.clear();
    // reverse(ans.begin(),ans.end());
    for(int i = ans.size()-1; i>=0;i--){
        for(int j = 0 ; j<ans[i].size();j++){
            res.push_back(ans[i][j]);
        }
    }
    return res;
    
}