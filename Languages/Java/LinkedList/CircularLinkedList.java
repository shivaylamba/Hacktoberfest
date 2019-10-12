//A simple program implementing the Circular Linked List and giving different operations in the linked list.
//Made by:- Shreyans Jain

import java.util.*;

class CircularLinkedList{
	Node head;
	Node tail;
	class Node{
		int data;
		Node next;
		public Node(int data){
			this.data=data;
		}
	}
	void printList(){
		if(head!=null){
			Node n=head;
			do{
				System.out.print(n.data+"\t");
				n=n.next;
			}while(n!=tail.next);
		}
		else System.out.println("Node empty");
		System.out.println();
	}
	int getSize(){
		int count=0;
		if(head!=null){
			Node n=head;
			do{
				count++;
				n=n.next;
			}while(n!=tail.next);
		}
		return count;
	}
	void addNodeAtEnd(int newData){
		Node newNode=new Node(newData);

		if(head==null){
			head=newNode;
			tail=newNode;
			tail.next=head;
		}
		else{
			tail.next=newNode;
			tail=newNode;
			newNode.next=head;
		}
	}
	void addNodeAtFront(int newData){
		Node newNode=new Node(newData);

		if(head==null){
			head=newNode;
			tail=newNode;
			tail.next=head;
		}
		else{
			newNode.next=head;
			head=newNode;
			tail.next=head;
		}
	}
	void addNodeAtAnyPosition(int newData,int newPosition){
		Node newNode=new Node(newData);

		if(newPosition<0||newPosition>getSize()){
			System.out.println("Insertion at this position not possible. Size of Linked List is "+getSize());
		}
		else{
			Node n=head;
			while(--newPosition>1){
				n=n.next;
			}
			newNode.next=n.next;
			n.next=newNode;
		}
	}
	void deleteNodeAtHead(){
		if(head.next==tail){
			head=null;
			tail=null;
		}
		else{
			head=head.next;
		}
	}
	void deleteNodeAtTail(){
		if(head.next==tail){
			head=null;
			tail=null;
		}
		else{
			Node n=head;
			Node temp=n;
			do{
				temp=n;
				n=n.next;
			}while(n!=tail);
			temp.next=head;
			tail=temp;
		}	
	}
	void deleteNodeAtAnyPosition(int oldPosition){
		if(oldPosition>0&&oldPosition<=getSize()){
			Node n=head;
			while(--oldPosition>1){
				n=n.next;
			}
			n.next=n.next.next;
		}
		else System.out.println("Deletion at this position is not possible. Size of Linked List is "+getSize());
	}
	boolean searchElementInList(int checkElement){
		Node n=head;
		do{
			if(n.data==checkElement) return true;
			n=n.next;
		}while(n!=tail.next);
		return false;
	}
	void reverseDisplay(Node n){
		if(n.next==head){
			System.out.print(n.data+"\t");
			return;
		}
			reverseDisplay(n.next);
			System.out.print(n.data+"\t");
	}
	boolean ifEmpty(CircularLinkedList l){
		if(l.head==null)
			return true;
		return false;
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);

		CircularLinkedList list=new CircularLinkedList();
   				if(list.ifEmpty(list))
					System.out.println("Node Empty");
				else
					System.out.println("Node have elements");
		int element;int position;
		System.out.println("Enter the size of nodes");
		int n=in.nextInt();
		
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++){
			element=in.nextInt();
			list.addNodeAtEnd(element);
		}
		list.printList();

		System.out.println("Enter element to be inserted at front");
		element=in.nextInt();
		list.addNodeAtFront(element);
		list.printList();

		System.out.println("Enter element to be inserted at end");
		element=in.nextInt();
		list.addNodeAtEnd(element);
		list.printList();

		System.out.println("Enter element and position where it is to be inserted");
		element=in.nextInt();
		position=in.nextInt();
		list.addNodeAtAnyPosition(element,position);
		list.printList();	

		System.out.println("Deletion of HEAD");
		list.deleteNodeAtHead();
		list.printList();

		System.out.println("Deletion of TAIL");
		list.deleteNodeAtTail();
		list.printList();

		System.out.println("Enter position where element is to be deleted");
		position=in.nextInt();
		list.deleteNodeAtAnyPosition(position);
		list.printList();

		System.out.println("Enter the element to be searched in Linked List");
		element=in.nextInt();
		if(list.searchElementInList(element))
			System.out.println("Search element found ");
		else
			System.out.println("Search element not found");

				if(list.ifEmpty(list))
					System.out.println("Node Empty");
				else
					System.out.println("Node have elements");

		System.out.println("Original list");
		list.printList();

		System.out.print("Reverse display: \t");
		list.reverseDisplay(list.head);
	}

}