#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define GLOBALSPACE 5

// Node class
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    friend class BST;
};

// BST class
class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    bool isTreeEmpty();
    void insertNode();
    Node * insertNodeRec(Node *, Node *);
    void preOrder(Node *);
    void inOrder(Node *);
    void postOrder(Node *);
    void preOrderNonRec(Node *);
    void inOrderNonRec(Node *);
    void postOrderNonRec(Node *);
    void levelOrder(Node *);
    int search(Node *, int);
    Node * minValNode(Node *node);
    Node * deleteNode(Node *, int);
    int height(Node *);
};

// If Tree is Empty
// Time Complexity - O(1)
bool BST ::isTreeEmpty()
{
    return (!root);
}

// Insert Node Non-Recursive
// Time Complexity - O(n)
void BST ::insertNode()
{
    int val;
    cout << "Enter data: ";
    cin >> val;

    Node *newnode = new Node(val);

    if (isTreeEmpty())
        root = newnode;

    else
    {
        Node *temp = root;

        while (temp != NULL)
        {
            if (newnode->data == temp->data)
            {
                cout << "Node Already Exists!\n\n";
                return;
            }

            else if (newnode->data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newnode;
                    break;
                }

                temp = temp->left;
            }

            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }

                temp = temp->right;
            }
        }
    }

    cout << val << " Inserted Successfully!\n\n";
}

// Insert Node Recursive
// Time Complexity - O(n)
Node* BST ::insertNodeRec(Node *head, Node* newNode)
{
    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    if (newNode->data == head->data)
    {
        cout << "Node Already Exists!\n\n";
        return head;
    }

    if (newNode->data < head->data)
    {
        head->left = insertNodeRec(head->left,newNode);
    }

    else if (newNode->data > head->data)
    {
        head->right = insertNodeRec(head->right, newNode);
    }

    return head;
}

// Preorder Traversal Recursive
// Time Complexity - O(n)
void BST ::preOrder(Node *head)
{
    if(head == NULL)
        return;

    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

// Inorder Traversal Recursive
// Time Complexity - O(n)
void BST ::inOrder(Node *head)
{
    if (head == NULL)
        return;

    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

// Postorder Traversal Recursive
// Time Complexity - O(n)
void BST ::postOrder(Node *head)
{
    if (head == NULL)
        return;

    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

// Preorder Traversal Non-Recursive
// Time Complexity - O(n)
void BST ::preOrderNonRec(Node *head)
{
    if(isTreeEmpty())
        return;

    stack<Node *> s;

    s.push(root);

    while(!s.empty())
    {
        Node *node = s.top();
        s.pop();

        cout << node->data << " ";

        if(node->right)
            s.push(node->right);
        
        if(node->left)
            s.push(node->left);
    }
}

// Inorder Traversal Non-Recursive
// Time Complexity - O(n)
void BST ::inOrderNonRec(Node *head)
{
    if (isTreeEmpty())
        return;

    stack<Node *> s;

    Node *curr = head;

    while(curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();

        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

// Postorder Traversal Non-Recursive
// Time Complexity - O(n)
void BST ::postOrderNonRec(Node *head)
{
    if (isTreeEmpty())
        return;

    stack<Node *> s1,s2;

    s1.push(root);
    Node *node;

    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);

        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

// Levelorder Traversal Non-Rec
// Time Complexity - O(n)
void BST ::levelOrder(Node *head)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();

        q.pop();

        cout << node->data << " ";

        if(node->right)
            q.push(node->right);
        
        if(node->left)
            q.push(node->left);
    }
    
}

// Search Data in BST
// Time Complexity - O(n)
int BST ::search(Node *head, int val)
{
    if(head != NULL)
    {
        while (head != NULL)
        {
            if (head->data == val)
                return 1;

            if (head->data > val)
                head = head->left;

            else
                head = head->right;
        }
    }

    return 0;
}

// Find Minimum Node
// Time Complexity - O(n)
Node* BST ::minValNode(Node* node)
{
    while(node->left)
        node = node->left;

    return node;
}

// Delete Data in BST
// Time Complexity - O(n)
Node* BST ::deleteNode(Node *head, int val)
{
    if(head == NULL)
        return head;

    if(val < head->data)
        head->left = deleteNode(head->left, val);

    else if (val > head->data)
        head->right = deleteNode(head->right, val);

    else
    {
        Node *temp = NULL;

        if(head->left == NULL)
        {
            temp = head->right;

            delete head;

            return temp;
        }

        else if (head->right == NULL)
        {
            temp = head->left;

            delete head;

            return temp;
        }

        else
        {
            temp = minValNode(head->right);

            head->data = temp->data;

            head->right = deleteNode(head->right, temp->data);
        }
    }

    return head;
}

// Height of BST Recursive
// Time Complexity - O(n)
int BST ::height(Node *head)
{
    if(head == NULL)
        return -1;

    int lheight = height(head->left);
    int rheight = height(head->right);

    if(lheight > rheight)
        return (lheight+1);
    
    else
        return (rheight+1);
}

// main Function
int main()
{
    int choice, val;
    BST obj;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit.\n\n";
        cout << "1.Insert\n2.Preorder Traversal Recursive\n3.Inorder Traversal Recursive\n4.Postorder Traversal Recursive\n5.Preorder Traversal Recursive\n6.Inorder Traversal Recursive\n7.Postorder Traversal Recursive\n8.Level Order Traversal\n9.Search Node\n10.Delete Node\n11.Height\n";

        cout << "\nEnter Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            obj.insertNode();
            break;

        case 2:
            cout << "Preorder Traversal:\n";
            obj.preOrder(obj.root);
            cout << endl;
            break;

        case 3:
            cout << "Inorder Traversal:\n";
            obj.inOrderNonRec(obj.root);
            cout << endl;
            break;
        
        case 4:
            cout << "Postorder Traversal:\n";
            obj.postOrderNonRec(obj.root);
            cout << endl;
            break;

        case 5:
            cout << "Preorder Traversal Non-rec:\n";
            obj.preOrderNonRec(obj.root);
            cout << endl;
            break;

        case 6:
            cout << "Inorder Traversal Non-rec:\n";
            obj.inOrder(obj.root);
            cout << endl;
            break;

        case 7:
            cout << "Postorder Traversal Non-rec:\n";
            obj.postOrder(obj.root);
            cout << endl;
            break;

        case 8:
            cout << "Levelorder Traversal:\n";
            obj.levelOrder(obj.root);
            cout << endl;
            break;            

        case 9 : cout << "Enter Data to Search: ";
            cin >> val;

            if(obj.search(obj.root, val))
                cout << "Data Found\n";
            else
                cout << "Data Not Found\n";

            break;

        case 10:
            cout << "Enter Data to Delete: ";
            cin >> val;
            
            if(obj.search(obj.root,val))
            {
                obj.deleteNode(obj.root, val);
                cout << val << " Deleted Successfully!\n";
            }
            else
                cout << "Data Not Found!\n";

            break;

        case 11:
            cout << "Height: " << obj.height(obj.root) << endl;

            break;

        default:
            cout << "Invalid Option!\n";
        }

    } while (choice != 0);

    return 0;
}
