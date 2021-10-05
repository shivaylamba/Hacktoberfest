/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root==NULL) return root;
       Node* main=root;
        // iterating all the nodes in the current level
    while(main->left!=NULL)
        // will iterate till the left most node
        // in the bottom left
    {
        Node* head=main;
        while(head!=NULL)
        {
          head->left->next=head->right;
            if(head->next!=NULL){
                // this takes place from the
                // 3rd level
                head->right->next=head->next->left;
            }
            head=head->next;
        }
        main=main->left;
        }
        return root;
        // keeping the root undisturbed
    }
};