/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
Example 1:
Input:
       1
     /  \
    2    3
Output: 3
Example 2:
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
*/
// } Driver Code Ends
/* Tree node structure  used in the program
  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/*
       Approach - 1 
    Time Complexity O(n)
    Space Complexity o(n)
*/
class Solution {
  private:
  pair<int,int> fastDiameter(Node* root){
      if(root==nullptr){
          pair<int,int> p = make_pair(0,0);
          return p;
      }
      
      pair<int,int> left = fastDiameter(root->left);
      pair<int,int> right = fastDiameter(root->right);
      
      int opt1 = left.first , opt2 = right.first;
      int opt3 = left.second + right.second +1;
      
      pair<int,int> ans ;
      ans.first = max(opt1,max(opt2,opt3)); // daimeter of binary tree
      ans.second = max(left.second,right.second)+1; // height
      
      return ans;
  }
  public:
    // Function to return the diameter of a Binary Tree.  
    int diameter(Node* root) {
        // Your code here
        if(root==nullptr) return 0;
        return fastDiameter(root).first;
    }
};
/*
    Approach - 2
    Time Complexity O(n^2)
    Space Complexity o(n)
*/
class Solution {
  private:
    int height(Node* root){
      if(root==nullptr) return 0;
      
      int left = height(root->left);
      int right = height(root->right);
      int ans = max(left,right) +1;
      return ans ;
  }
  public:
        int diameter(Node* root) {
        // Your code here
        if(root==nullptr) return 0;
        
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + 1 + height(root->right);
        
        int ans = max(opt1 , max(opt2 , opt3));
        return ans;
    }
};