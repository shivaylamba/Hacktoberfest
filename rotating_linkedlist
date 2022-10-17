import java.util.*;
class Node {
  int num;
  Node next;
  Node(int a) {
    num = a;
    next = null;
  }
}
class TUF {
  //utility function to insert node at the end of the list
  static Node insertNode(Node head, int val) {
    Node newNode = new Node(val);
    if (head == null) {
      head = newNode;
      return head;
    }
    Node temp = head;
    while (temp.next != null) temp = temp.next;

    temp.next = newNode;
    return head;
  }
  //utility function to rotate list by k times
  static Node rotateRight(Node head, int k) {
    if (head == null || head.next == null) return head;
    for (int i = 0; i < k; i++) {
      Node temp = head;
      while (temp.next.next != null) temp = temp.next;
      Node end = temp.next;
      temp.next = null;
      end.next = head;
      head = end;
    }
    return head;
  }
  //utility function to print list
  static void printList(Node head) {
    while (head.next != null) {
      System.out.print(head.num + "->");
      head = head.next;
    }
    System.out.println(head.num);

  }

  public static void main(String args[]) {
    Node head = null;
    //inserting Node
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);

    System.out.println("Original list: ");
    printList(head);

    int k = 2;
    Node newHead = rotateRight(head, k); //calling function for rotating 
    right of the nodes by k times

    System.out.println("After " + k + " iterations: ");
    printList(newHead); //list after rotating nodes

  }
}
