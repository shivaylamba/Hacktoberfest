/*
Array to BST
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.
Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.
Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.
Examples :
Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     / \   / \
    1 3  5 7
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)
Constraints:
1 ≤ nums.size() ≤ 105
1 ≤ nums[i] ≤ 105
*/
/*
    DFS Traversal
Time Complexity: O(n);
Space Complexity: O(log(n));
*/
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
  Node* solve(vector<int>&nums,int i,int j){
      if(i>j) return nullptr;
        int mid = i + (j - i)/2;
        Node* root = new Node(nums[mid]);
        root->left =solve(nums,i,mid-1);
        root->right = solve(nums,mid+1,j);
        return root;
  }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        return solve(nums,0,nums.size()-1);
    }
};
/*
    BFS Traversal
Time Complexity: O(n);
Space Complexity: O(n);
*/
Node* sortedArrayToBST(vector<int>& nums)
{
    // if the array is empty return NULL
    if (nums.empty()) {
        return NULL;
    }
 
    int n = nums.size();
    int mid = n / 2;
    Node* root = new Node{ nums[mid], NULL, NULL };
    // initializing queue
    queue<pair<Node*, pair<int, int> > > q;
    // push the root and its indices to the queue
    q.push({ root, { 0, mid - 1 } });
    q.push({ root, { mid + 1, n - 1 } });
 
    while (!q.empty()) {
        // get the front element from the queue
        pair<Node*, pair<int, int> > curr = q.front();
        q.pop();
 
        // get the parent node and its indices
        Node* parent = curr.first;
        int left = curr.second.first;
        int right = curr.second.second;
 
        // if there are elements to process and parent node
        // is not NULL
        if (left <= right && parent != NULL) {
            int mid = (left + right) / 2;
            Node* child = new Node{ nums[mid], NULL, NULL };
 
            // set the child node as left or right child of
            // the parent node
            if (nums[mid] < parent->val) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
 
            // push the left and right child and their
            // indices to the queue
            q.push({ child, { left, mid - 1 } });
            q.push({ child, { mid + 1, right } });
        }
    }
 
    return root;
}