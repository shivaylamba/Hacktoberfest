import java.util.Scanner;

class Node {
    int data;
    Node next;
}

public class LinkedList {
    static Node head = null;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        while (true) {
            System.out.println("\n1.Insert\n2.Delete\n3.Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    insert();
                    break;
                case 2:
                    delete();
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");
            }
        }
    }

    public static void insert() {
        Node ptr, temp;
        int item;
        ptr = new Node();

        Scanner scanner = new Scanner(System.in);

        if (ptr == null) {
            System.out.println("Overflow");
            return;
        }

        System.out.print("Enter the value: ");
        item = scanner.nextInt();
        ptr.data = item;

        if (head == null) {
            ptr.next = null;
            head = ptr;
        } else {
            temp = head;
            while (temp.next != null)
                temp = temp.next;
            temp.next = ptr;
            ptr.next = null;
        }
        System.out.println("Node inserted");
    }

    public static void delete() {
        Node ptr, temp;
        if (head == null) {
            System.out.println("Underflow");
            return;
        } else if (head.next == null) {
            head = null;
            System.out.println("Node deleted");
        } else {
            ptr = head;
            while (ptr.next != null) {
                temp = ptr;
                ptr = ptr.next;
            }
            temp.next = null;
            ptr = null; // Free the memory (in C, you would use free(ptr);)
            System.out.println("Node deleted");
        }
    }
}
