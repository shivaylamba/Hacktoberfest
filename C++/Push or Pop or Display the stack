#include <stdio.h>
 
#define MAX 100
 
int arr[MAX],n,i,top=-1,choice=0;
 
 
void push(){
    printf("\n Enter an element to be pushed: ");
    scanf("%d",&n);
    top++;
    arr[top] = n;
    printf("\n");
}
 
void pop(){
    if(top==-1){
        printf("\n Underflow error! The stack is empty.");
    }
    else{
        printf("\n The popped element is : %d",arr[top]);
        top--;
    }
    printf("\n");
}
 
void display(){
 
    if(top==-1){
        printf("\n Underflow error! The stack is empty.");
    }
    else{
        printf("\n-----Displaying stack-----");
        printf("\n The elements of stack: ");
        for(i=0;i<top+1;i++){
            printf("%d, ",arr[i]);
        }
    }
    printf("\n");
    
}
 
int main() {
    // stack implementation
    while(choice!=4){
    
    printf("\n ----STACK IMPLEMENTATION------");
    printf("\n 1.Push an element");
    printf("\n 2. Pop stack");
    printf("\n 3.Display stack");
    printf("\n 4. End");
    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Good Bye!");
            break;
        default:
            printf("Wrong option!");
        
    }
    }
    printf("\n The program has been terminated!");
 
    return 0;
}
