#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

void insert(node* &head, int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* removeNthFromEnd(node* head, int n, int num) {
        node* temp=head;

        //counting the number of nodes if case we don't know

        // int count=0;
        // while(temp!=NULL)
        // {
        //     count++;
        //     temp=temp->next;
        // }

        node* prev;
        temp=head;

        //if node need to delete is equal to size of list we only delete first node an return 

        if(num==n)
        {
            head=head->next;
            return head;
        }

        // other case not equal
        
        while(num-n)
        {
            prev=temp;
            temp=temp->next;
            num--;
        }
        prev->next=temp->next;
        temp=temp->next;
        return head;
    }

int main()
{
    node *head = NULL;
    int n,pos;

    // Enter the number of nodes
    cin>>n;

    //Entering the value and insert the node using insert() function
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        insert(head,val);
    }

    //Enter the nth node that to be deleted
    cin>>pos;

    //Calling the function for remove nth node form last

    head=removeNthFromEnd(head,pos,n);

    //displaying modified list

    display(head);
    return 0;
}
