struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      if(!node){
          return ans;
      }
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          Node *t = q.front();
          ans.push_back(t->data);
          if(t->left){
              q.push(t->left);
          }
          if(t->right){
              q.push(t->right);
          }
          q.pop();
      }
      return ans;
    }
};
