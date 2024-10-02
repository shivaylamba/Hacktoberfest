/*
Remove duplicate element from sorted Linked List
Given a singly linked list consisting of N nodes. The task is to remove
duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.
Example 1:
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list
2 ->2 -> 4-> 5, only 2 occurs more
than 1 time. So we need to remove it once.
Example 2:
Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times. So we need to remove
any four 2.
Your Task:
The task is to complete the function removeDuplicates() which takes the head of
input linked list as input. The function should remove the duplicates from linked
list and return the head of the linkedlist.
Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
Constraints:
1 <= Number of nodes <= 105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};
void print(Node *root)
{
  Node *temp = root;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
Node *removeDuplicates(Node *root);
int main()
{
  // your code goes here
  int T;
  cin >> T;
  while (T--)
  {
    int K;
    cin >> K;
    Node *head = NULL;
    Node *temp = head;

    for (int i = 0; i < K; i++)
    {
      int data;
      cin >> data;
      if (head == NULL)
        head = temp = new Node(data);
      else
      {
        temp->next = new Node(data);
        temp = temp->next;
      }
    }

    Node *result = removeDuplicates(head);
    print(result);
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
//Function to remove duplicates from sorted linked list.
// Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 Node* curr = head;
 while(curr!=nullptr){
     if(curr->next!=nullptr && curr->data == curr->next->data){
         Node* pointToNextNodeOfDelete = curr->next->next;
         Node* nodeToDelete = curr->next;
         delete(nodeToDelete);
         curr->next = pointToNextNodeOfDelete;
     }
     else{
          curr=curr->next;
     }
     }
     return head;
 }
 // Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
 Node *removeDuplicates2(Node *head)
{
  Node *curr = head;
  while (curr != nullptr && curr->next != nullptr)
  {
    if (curr->val == curr->next->val)
    {
      curr->next = curr->next->next;
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}
// Optimized Approach // set
// Time Complexity O(n)
// Space Complexity O(n)
Node *removeDuplicates3(Node *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 Node* curr = head;
 Node* prev = nullptr;
 set<int> set;
 while(curr!=nullptr){
     if(set.count(curr->data)){
         prev->next = curr->next;
     }
     else{
         set.insert(curr->data);
         prev = curr;
     }
     curr=curr->next;
 }
 return head;
 }
 // Optimized Approach // unoredered_Set
// Time Complexity O(n)
// Space Complexity O(n)
 Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 Node* curr = head;
 Node* prev = nullptr;
 unordered_set<int> set;
 while(curr!=nullptr){
     if(set.find(curr->data)!=set.end()){
         prev->next = curr->next;
     }
     else{
         set.insert(curr->data);
         prev = curr;
     }
     curr=curr->next;
 }
 return head;
 }