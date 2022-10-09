#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node* next;
};
Node* createNode(int data){
   struct Node* newNode = new Node;
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}
int nodeCount(struct Node* head){
   int count = 0;
   while (head != NULL) {
      head = head->next;
      count++;
   }
   return count;
}
struct Node* deleteMiddle(struct Node* head){
   if (head == NULL)
      return NULL;
   if (head->next == NULL) {
      delete head;
      return NULL;
   }
   Node* temphead = head;
   int count = nodeCount(head);
   int mid = count / 2;
   while (mid-- > 1) {
      head = head->next;
   }
   head->next = head->next->next;
   return temphead;
}
void printList(Node * ptr){
   while (ptr!= NULL) {
      cout << ptr->data << "->";
      ptr = ptr->next;
   }
   cout << "NULL"<<endl;
}
int main(){
   struct Node* head = createNode(2);
   head->next = createNode(4);
   head->next->next = createNode(6);
   head->next->next->next = createNode(8);
   head->next->next->next->next = createNode(10);
   cout << "Original linked list"<<endl;
   printList(head);
   head = deleteMiddle(head);
   cout<<endl;
   cout << "After deleting the middle of the linked list"<<endl;
   printList(head);
   return 0;
}
