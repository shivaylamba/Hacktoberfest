/*Given a pointer to the head node of a linked list, find the middle node & Nth node from end of the list.

findMiddle(head) : Return the middle node if number of nodes in linked list in odd, otherwise there will be two middle nodes and return the second middle node (return -1 if list is empty).

findNLast(head, n): Return the Nth node from end of the list. If N is greater than size of the list, return the last node of list (return -1 if list is empty).*/


import java.util.Scanner;
// Other imports go here
// Do NOT change the class name
class Node
{
  int data;
  Node next;
  Node(int d)
  {
    data=d;
  }
}

class Main
{
  static Node insertEnd(Node head, int data)
  {
    Node newLink = new Node(data);
    Node last = head;
    newLink.next = null;   // link new node to NULL as it is last node
    if (head == null)  // if list is empty add in beginning.
    {
      head = newLink;
      return head;
    }
    while (last.next != null)  // Find the last node
      last = last.next;
    last.next = newLink;  // Add the node after the last node of list
    return head;
  }

  static void forwardPrint(Node head)
  {
    Node current = head; // start at beginning of list
    while(current != null) // until end of list,
    {
      System.out.print(current.data + " "); // print data
      current = current.next; // move to next link
    }
  }
  /* class Node
{
  int data;
  Node next;
} */
static int findMiddle(Node head) 
{
  if(head==null)
    return -1;
	Node slow = head;
  Node fast = head;
  while(fast!=null&&fast.next!=null){
    slow=slow.next;
    fast=fast.next.next;
  }
  return slow.data;
}
static int findNLast(Node head, int n)
{
  if(head==null)
    return -1;
	Node first=head;
  Node second=head;
  int i=0;
  while(second.next!=null){
    if(i<n-1)
      second=second.next;
    else{
      first=first.next;
      second=second.next;
    }
    i++;
  }
  if(i<n-1)
    return second.data;
  return first.data;
}
