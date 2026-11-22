class Node {
    int data;
    Node next;
    Node prev;

    // Constructor
    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class DoublyLinkedList {
    
    // Function to print the list from head to end
    static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create nodes
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        // Link nodes
        head.next = temp1;
        temp1.prev = head;
        temp1.next = temp2;
        temp2.prev = temp1;

        // Print list
        printList(head);
    }
}
