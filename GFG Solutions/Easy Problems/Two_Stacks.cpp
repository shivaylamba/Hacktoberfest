/*
 Two Stacks
Sample Input 1:
3 5
1 1 3
1 2 4
1 1 5
2 1
2 2
Sample output 1:
5
4
Explanation of sample input 1:

Here every step shows a snapshot of 2 stacks after each operation.

Initialising the size of the array to 3, twoStack = new TwoStack(3).
Then operation on two stacks occurs as follows:
twoStack.push1(3) // pushing 3 in stack1.
twoStack.push2(4) // pushing 4 in stack2.
twoStack.push1(5) // pushing 5 in stack1.
twoStack.pop1() // popping out from stack2, it returns 5.
twoStack.pop2() // popping out from stack2, it returns 4.
Sample Input 2:
3 10
1 1 2
1 1 4
1 1 3
1 2 5
2 2
2 1
1 2 6
2 2
2 1
1 2 7
Sample output 2:
-1
3
6
4
Explanation of sample input 2:

Here every step shows a snapshot of 2 stacks after each operation.

Initialising the size of the array to 3, twoStack = new TwoStack(3).
Then operation on two stacks occurs as follows:
twoStack.push1(2) // pushing 2 in stack1.
twoStack.push1(4) // pushing 4 in stack1.
twoStack.push1(3) // pushing 3 in stack1.
twoStack.push2(5) // pushing 5 in stack2, but 3 elements are already in the array and there is no empty space hence it cannot be added.
twoStack.pop2() // popping out from stack2, it is already empty hence returns -1.
twoStack.pop1() // popping out from stack1, it returns 3.
twoStack.push2(6) // pushing 6 in stack2.
twoStack.pop2() // popping out from stack2, it returns 6.
twoStack.pop1() // popping out from stack1, it returns 4.
twoStack.push2(7) // pushing 7 in stack2.
*/
#include <bits/stdc++.h> 
class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast a empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
       // Other stack is Overflow
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
       // Other stack is Overflow
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
       // Other stack is underflow
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
       // Other stack is underflow
            return -1;
        }
    }

};
