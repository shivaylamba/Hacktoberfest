#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node* MidpointLL(Node *h , Node *t){
    Node *slow = h;
    Node *fast = h->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Merge(Node *h1 , Node *h2 , Node *t){
    if(h1 == NULL){
        return h2;
    }
    if(h2 == NULL){
        return h1;
    }
    Node *fh = NULL , *ft = NULL;
   Node *th1 = h1 , *th2 = h2;
  while(th1 != h2 && th2 != t){
    if(th1->data < th2->data){
        if(fh == NULL){
            fh = th1;
            ft = th1;
            th1 = th1->next;
        }
        else{
            ft->next = th1;
            ft = ft->next;
           th1 = th1->next;
        }
    }
    else{
         if(fh == NULL){
            fh = th2;
            ft = th2;
            th2 = th2->next;
        }
        else{
            ft->next = th2;
            ft = ft->next;
             th2 = th2->next;
        }
    }
   }
   if(th1 != h2){
    ft->next = th1;
   }
  if(th2 != t){
    ft->next = th2;
   }
   return fh;
}
Node* MergeSortHelper(Node *head , Node *tail){
 
 Node *mid = MidpointLL(head , tail);
 Node *h1 = MergeSortHelper(head , mid);
 Node *h2 = MergeSortHelper(mid->next , tail);
 //tail->next = NULL;
 Node *h  = Merge(h1 , h2 , tail);

 return h;
}

Node* mergeSort(Node *head){
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    //DIVIDE
  Node *head1 = MergeSortHelper(head ,tail);
  return head1;
}




Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}