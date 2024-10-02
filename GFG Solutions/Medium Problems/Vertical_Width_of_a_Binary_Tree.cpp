/*
Vertical Width of a Binary Tree
Given a Binary Tree. You need to find and return the vertical width of the tree.

Examples :

Input:
         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
Input:
     1
    /  \
   2    3
Output: 3
Explanation: The above tree has 3 vertical lines, hence the answer is 3.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(height of the tree).

Constraints:
0 <= number of nodes <= 104
*/
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        if(!root) return 0;
        int mina = 0 , maxa = 0;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* frontNode = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(frontNode->left){
                mina = min(mina , hd -1 );
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                maxa = max(maxa , hd +1 );
                q.push({frontNode->right,hd+1});
            }
        }
        return (abs(mina) + 1 + maxa);
    }
};