#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *root;     //root node

void insert(int data)       //To insert the data into the tree
{
    node *temp=new node;
    temp->data=data;
    node *temp1,*cur;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    temp1=root;
    while(temp1!=NULL)
    {
        cur=temp1;
        if(data < temp1->data)
        {
            temp1=temp1->left;
            if(temp1==NULL)
            {
                cur->left=temp;
            }
        }
        else
        {
            temp1=temp1->right;
            if(temp1==NULL)
            {
                cur->right=temp;
            }
        }
    }
}

void preorder()         //Iterative preorder traversal
{
    cout<<"Preorder\n";
    stack<node*>ans;
    ans.push(root);
    while(!ans.empty())
    {
        node *cur=ans.top();
        ans.pop();
        cout<<cur->data<<" ";
        if(cur->right)
        {
            ans.push(cur->right);
        }
        if(cur->left)
        {
            ans.push(cur->left);
        }
    }
    cout<<endl;
}

void postorder()            //Iterative postorder travsersal
{
    cout<<"Postorder\n";
    stack<node*> s;
    s.push(root);
    stack<int>ans;
    while (!s.empty())
    {
        node* curr = s.top();
        s.pop();
        ans.push(curr->data);
        if(curr->left) 
        {
            s.push(curr->left);
        }
        if(curr->right) 
        {
            s.push(curr->right);
        }
    }
    while (!ans.empty())
    {
        cout<<ans.top()<< " ";
        ans.pop();
    }
    cout<<endl;

}


void inorder()          //Iterative inorder traversal
{
    cout<<"\nInorder\n";
    stack<node*>s;
    node *temp=root;
    while( temp || !s.empty())
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}



void rec_inorder(node *root)        //Recurive inorder traversal
{
    if(root!=NULL)
    {
        rec_inorder(root->left);
        cout<<root->data<<" ";
        rec_inorder(root->right);
    }
}


void rec_preorder(node *root)       //Recursive preorder traversal
{
    if(root!=NULL)
    {
        
        cout<<root->data<<" ";
        rec_preorder(root->left);
        rec_preorder(root->right);
    }
}


void rec_postorder(node *root)      //recursive postorder traversal
{
    if(root!=NULL)
    {
        rec_postorder(root->left);
        rec_postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    int n;      //No of inputs
    cin>>n;
    while(n--)
    {
        int val;
        cin>>val;
        insert(val);
    }
    cout<<"Recurive postorder traversal\n";
    rec_postorder(root);
    cout<<endl;
    postorder();
    cout<<"Recurive preorder traversal\n";
    rec_preorder(root);
    cout<<endl;
    preorder();
    cout<<"Recurive inorder traversal\n";
    rec_inorder(root);
    inorder();
    cout<<endl;
}