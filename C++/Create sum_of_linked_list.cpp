// C++ implementation to find the sum of
// nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node* next;
};
void push(struct Node** head_ref, int new_data) {
   struct Node* new_node = new Node;
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}
void nodesum(struct Node* head, int* sum) {
   if (!head)
      return;
   nodesum(head->next, sum);
   *sum = *sum + head->data;
}
int main() {
   struct Node* head = NULL;
   int sum= 0;
   push(&head, 95);
   push(&head, 60);
   push(&head, 87);
   push(&head, 6);
   push(&head, 12);
   nodesum(head,&sum);
   cout << "Sum of nodes = "<<sum;
   return 0;
}


//OUTPUT:
//Sum of nodes = 260
