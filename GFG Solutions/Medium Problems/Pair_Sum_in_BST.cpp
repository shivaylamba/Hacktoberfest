/*
Pair Sum in BST
Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 
Example 1:
Input:
        2
      /   \
     1     3
sum = 5
Output: 1 
Explanation: 
Nodes with value 2 and 3 sum up to 5.
Example 2:
Input:
           6
          /    
         5     
        /
       3 
     /  \
    1    4
sum = 2
Output: 0 
Explanation: 
There's no pair that sums up to 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isPairPresent() that takes a root node and a target value as a parameter and returns 1 if there's a pair of Nodes in the BST with values summing up to the target sum, else returns 0. 
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
Constraints:
1 ≤ Number of Nodes ≤ 105
1 ≤ Sum ≤ 106
*/
/*Complete the function below
Node is as follows
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
/*
    Using HashSet – O(n) time and O(n) space
Time Complexity: O(n), for the visiting each node of BST
Auxiliary Space: O(n), for storing nodes in hashSet
*/
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int dfs(Node* root,unordered_set<int> &set,int target){
        if(!root) return 0;
        if(set.count(target-root->data)) return 1;
        set.insert(root->data);
        return dfs(root->left,set,target) || dfs(root->right,set,target);
    
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    unordered_set<int> set;
    return dfs(root,set,target);
    }
};
/*
    USING INORDER TRAVERSAL
Time Complexity: O(n), for the inorder traversal and checking the pair.
Auxiliary Space: O(n), for storing the inorder traversal.
*/
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    vector<int> inorder(Node* root){
        vector<int> ans;
        if(!root)return ans;
        vector<int> left = inorder(root->left) ;
        ans.insert(ans.end(),left.begin(),left.end());
        ans.push_back(root->data);
        vector<int> right = inorder(root->right);
        ans.insert(ans.end(),right.begin(),right.end());
        return ans;
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    vector<int> ans = inorder(root);
    int i  =0 , j = ans.size()-1;
    while(i<j){
        if((ans[i]+ans[j]) == target) return 1;
        else if((ans[i]+ans[j]) > target) j--;
        else i++;
    }
    return 0;
    }
};