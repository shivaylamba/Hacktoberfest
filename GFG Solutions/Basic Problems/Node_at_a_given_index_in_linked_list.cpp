/*
Given a singly linked list with N nodes and a number X. The task is to find the node at the given index (X)(1 based index) of linked list. 

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains space seperated two integers, length of linked list and X.

Output:
For each testcase, there will be single line of output containing data at Xth node.

User Task:
The task is to complete the function GetNth() which takes head reference and index as arguments and should return the data at Xth position in the linked list.

Constraints:
1 <= T <= 30
1 <= N <= 100
X <= N
1 <= value <= 103

Example:
Input:
2
6 5
1 2 3 4 657 76
10 2
8 7 10 8 6 1 20 91 21 2

Output:
657
7

Explanation:
Testcase 1: Element at 5th index in the linked list is 657 (1-based indexing).
*/
//{ Driver Code Starts
// C program to find n'th node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};
 
struct node* push(struct node* head, int d)
{
   
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));

    new_node->data  = d;
    new_node->next = NULL;
    
    if (head == NULL) return new_node;
    
    struct node* h = head;
    while (head->next != NULL) head = head->next;
    head->next = new_node;
    
    return h;
}

int GetNth(struct node* head, int index);


/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
    
    cin>>T;
    
    while(T--){
    struct node *head = NULL;
        
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            head = push(head, l);
        }
   
    printf("%d\n", GetNth(head, k));  
    getchar();
    }
    return 0;
}
 
// } Driver Code Ends
// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node* head, int index){
  // Code here
  int i = 0;
  while(i<index-1){
       head=head->next;
       i++;
  }
  return head->data;
}
