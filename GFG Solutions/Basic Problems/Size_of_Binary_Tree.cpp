/*
Size of Binary Tree
Given a binary tree of size n, you have to count the number of nodes in it. For example, the count of nodes in the tree below is 4.

        1
     /      \
   10      39
  /
5

Example 1:
Input:
1 2 3
Output:
3
Explanation:
Given Tree is :
                              1
                             /  \
                            2   3
There are 3 nodes in the tree.
Example 2:
Input:
10 5 9 N 1 3 6 
Output:
6
Explanation:
Given Tree is :
                              10
                             /  \
                           5     9
                            \    / \
                             1 3   6
There are 6 nodes in the tree.
User Task:
You don't need to read input or print anything. Your task is to complete the function getSize() which takes the tree head node and returns an integer representing the number of nodes in the tree.

Expected Time Complexity: O(n)
Expected Auxillary Space: O(h), where h is the height of the binary tree

Constraints:
1 <= n <= 105
1 <= values of nodes <= 106
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* inputTree(){
    string treeString;
    getline(cin,treeString);
    Node* root = buildTree(treeString);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// } Driver Code Ends
/*

Definition for Binary Tree Node
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

class Solution {
private:
void solve(Node* node ,int &count){
    if(node==nullptr){return ;}
    solve(node->left,count);
    count++;
    solve(node->right,count);
}
  public:
  /* Computes the number of nodes in a tree. */
int size(Node* node) 
{ 
    if (node == NULL) 
        return 0; 
    else
        return(size(node->left) + 1 + size(node->right)); 
} 
    int getSize(Node* node) {
        // code here
        int count = 0;
solve(node,count);
return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        Node* node = inputTree();
        
        Solution obj;
        int res = obj.getSize(node);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends