import java.util.Scanner;
class Node {
    int val;
    Node next;
  
    Node(int x) {
        val = x;
        next = null;
    }
}

class stack {
	Node top;

	public Node peek() {
		if(top!= null) {
			return top;
		}
		return null;
	}

	public Node pop() {
		if(top==null) {
			return null;
		}
		else {
			Node temp = new Node(top.val);
			top = top.next;
			return temp;
		}
	}

	public void push(Node n) {
		if(n!=null) {
			n.next = top;
			top=n;
		}
	}
	public void travese() {
		Node n=peek();
		if(n == null) {
			System.out.println("Empty stack");
		}
		while(n!=null){
			System.out.print(n.val + "->");
			n = n.next;
		}
		System.out.println();
	}
}

class stack_main {
	public static void main(String[] args) {
		stack stk =new stack();
		Scanner sc = new Scanner(System.in);
		int ch, data;
		char ch1='Y';
		while(ch1 =='Y' || ch1 == 'y') {
			System.out.println("Menu\n1.Push\n2.Pop\n3.Traversal");
			ch = sc.nextInt();
			switch(ch) {
				case 1:
					System.out.println("Enter the data you want to push");
					data = sc.nextInt();
					stk.push(new Node(data));
					break;

				case 2:
					stk.pop();
					break;

				case 3:
					System.out.println("The stack is");
					stk.travese();
					break;

				default:
					System.out.println("Enter the a correct value");
					break;
			}
			System.out.println("Do you wish to continue");
			ch1=sc.next().charAt(0);
		}
	}
}
