/*
Burning Tree
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.
Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
Constraints:
1 ≤ N ≤ 104
*/
//User function Template for C++

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
  private:
  Node* creataParenetMapping(Node* root,int target,map<Node*,Node*>&nodeToParent){
      Node* res = NULL;
      queue<Node*> q;
      q.push(root);
      nodeToParent[root] = nullptr;
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front->data == target) {   res = front; }
          if(front->left){ 
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              nodeToParent[front->right] = front;
              q.push(front->right);
          }
      }
      return res;
  }
  
  void burnTree(Node* root,map<Node*,Node*>&nodeToParent,int &time){
      queue<Node*> q;
      map<Node*,bool> visited;
      
      q.push(root);
      visited[root] = 1;
      
      while(!q.empty()){
          bool flag = 0 ;
          int size= q.size();
          
          for(int i=0; i<size ; i++){
              // process neghbouring node;
              Node* front = q.front();
              q.pop();
              if(front->left && !visited[front->left]){
                  flag =1;
                  q.push(front->left);
                  visited[front->left] = 1;
              }
              if(front->right && !visited[front->right]){
                  flag =1;
                  q.push(front->right);
                  visited[front->right] = 1;
              }
              if(nodeToParent[front] && !visited[nodeToParent[front]] ){
                  flag =1;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]] = 1;
              }
          }
          
          if(flag == 1) time++;
      }
  }
  
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int time = 0 ;
        map<Node*,Node*>nodeToParent;
        Node* targetNode = creataParenetMapping(root,target,nodeToParent);
        burnTree(targetNode,nodeToParent,time);
        return time;
        
    }
};