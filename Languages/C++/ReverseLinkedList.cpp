#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};

node* create_ll(int n)
{
	int count=0;
	node* head=NULL;
	node* tail=NULL;
	while(count!=n)
	{
		int x;
		cin>>x;
		node* curnode=new node(x);
		if(!head)
		{
			head=curnode;
			tail=curnode;
		}
		else
		{
			tail->next=curnode;
			tail=tail->next;
		}
		count++;
	}
	return head;
}

void display(node* head)
{
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
}

node* reverse(node* head)
{
	node* prevnode=NULL;
	node* curnode=head;
	while(curnode)
	{
		node* ahead=curnode->next;
		curnode->next=prevnode;
		prevnode=curnode;
		curnode=ahead;
	}
	return prevnode;
}

int main()
{
	int n;
	cin>>n;
	node* head=create_ll(n);
	node* new_head=reverse(head);
	display(new_head);
	cout<<endl;
}