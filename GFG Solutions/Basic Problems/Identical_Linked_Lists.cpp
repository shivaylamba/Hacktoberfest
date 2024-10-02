/*
Given two Singly Linked List of N and M nodes respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Example 1:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: Not identical 
Example 2:

Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: Identical
 
Your Task:
The task is to complete the function areIdentical() which takes the head of both linked lists as arguments and returns True or False.

Constraints:
1 <= N <= 103

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
*/
// } Driver Code Ends
//Function to check whether two linked lists are identical or not. 
//-----------------method -1 ---------------------------------------------//
// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)
int length(struct Node* head){
    Node* temp = head;
    int i = 0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}
bool areIdentical(struct Node *head1, struct Node *head2)
{
    Code here
    if(length(head1)!=length(head2)){
        return 0;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data!=head2->data){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return 1;
}
//-----------------method-2 Optimized ---------------------------------------------//
// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)
bool areIdenticalOptimized(struct Node *head1, struct Node *head2)
{
    while(head1!=NULL && head2!=NULL){
        if(head1->data!=head2->data){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return (head1==NULL && head2==NULL);
}
//-------------------------------------------------------------------------------------------------//
bool areIdentical(struct Node *head1, struct Node *head2) {
    // Code here
    while(head1 && head2){
        if(head1->data != head2->data) return 0;
        head1 = head1->next;
        head2= head2->next;
    }
    return (!head1 && !head2);
}