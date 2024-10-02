/*
449. Serialize and Deserialize BST
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*front = q.front();
            q.pop();
            if(!front) s.append("#,");
            else s.append(to_string(front->val)+',');

            if(front){
                q.push(front->left);
                q.push(front->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front  = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                front->left = nullptr;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                front->left = leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="#"){
                front->right = nullptr;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;