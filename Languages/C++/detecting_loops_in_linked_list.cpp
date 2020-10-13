#include <bits/stdc++.h> 
using namespace std;

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 

	new_node->data = new_data; 

	new_node->next = (*head_ref); 

	(*head_ref) = new_node; 
} 

bool detectLoop(struct Node* head) 
{ 
	if (head == NULL) return false;
    Node* hare = head->next;
    Node* tor = head;
    while(tor!=hare)
    {
        if(hare==NULL||hare->next==NULL)
            return false;
        tor = tor->next;
        hare = hare->next->next;
        
    }
    return true; 
} 


int main() 
{ 
	struct Node* head = NULL; 

	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 

	head->next->next->next->next = head; 

	if (detectLoop(head)) 
		cout << "Loop found"; 
	else
		cout << "No Loop"; 

	return 0; 
} 
