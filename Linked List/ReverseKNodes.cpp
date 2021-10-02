#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node **head,int x){
	Node* new_node = new Node();
	new_node->data = x;
	new_node->next = *head;
	*head = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
Node* reverse(Node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}


int main(){
	Node *head = NULL;
	int n;
	cout<<"Enter number of nodes you want in Linked List"<<endl;
	cin>>n;
	cout<<"Enter the values of "<<n<<" nodes"<<endl;
	int x;
	while(n--){
		cin>>x;
		push(&head,x);
	}
	cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
	
}
