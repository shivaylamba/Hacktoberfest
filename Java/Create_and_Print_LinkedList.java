// program to create and print a linked list

import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data){
        this.data = data;
        next = null;
    }
}

public class Create_and_Print_LinkedList {

    public static Node takeInput(){
        Scanner s = new Scanner(System.in);
        int data = s.nextInt();
        Node head = null;
        Node tail = null;
        // entering node values until -1 is encountered
        while(data!=-1){
            Node current = new Node(data);
            if(head == null){
                //make it point to first node
                head = current;
                tail = current;
            }
            else{
                tail.next = current; // connecting tail to current
                tail = tail.next;    // incrementing tail
            }
            data = s.nextInt();
        }
        s.close();
        return head;
    }

    public static void print(Node start){
        Node temp= start;
        
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        } 
        System.out.println();
    }

    public static void main(String[] args) {
        Node Head_of_LL = takeInput();
        print(Head_of_LL);
    }
}
