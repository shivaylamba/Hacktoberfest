package LAB3;

import java.util.Scanner;

class stack_using_array {
    static final int MAX = 1000;
    int top;
    int a[] = new int[MAX];     // Maximum size of Stack
    boolean isEmpty() {
        return (top < 0);
    }
    stack_using_array() {
        top = -1;
    }
    boolean push(int x) {
        if (top >= (MAX - 1)) {
            System.out.println("Stack Overflow");
            return false;
        }
        else {
            a[++top] = x;
            System.out.println(x + " pushed into stack");
            return true;
        }
    }
    int pop() {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    int peek() {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }
}
// Driver code
class Main {
    public static void main(String args[]) {
        stack_using_array s = new stack_using_array();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter value to push into stack : ");
        int x = scan.nextInt();
        s.push(x);
        System.out.println("\nEnter value to push into stack : ");
        int y = scan.nextInt();
        s.push(y);
        //s.push(30);
        //s.push(30);
        System.out.println("\nPOP operation :-");
        System.out.println(s.pop() + " Popped from stack");
    }
}
