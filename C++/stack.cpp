#include<bits/stdc++.h>
using namespace std;

struct myStack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct myStack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct myStack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
void push(struct myStack *ptr, int val){
    if(isFull(ptr)){
        cout<<"Stack overflow"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct myStack *ptr){
    if(isEmpty(ptr)){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display(struct myStack *ptr){
    if(isEmpty(ptr)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        for(int i=0; i<=ptr->top;i++){
            cout<<ptr->arr[i]<<" ";
        }
    }
}

int main(){
    struct myStack *sp=(struct myStack*)malloc(sizeof(myStack));
    cout<<"Enter the size of stack: ";
    cin>>sp->size;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    int n=0;
    int data;
    while(n!=4){
        cout<<"\nEnter the choices:\n 1. to push\n 2. to pop\n 3. display\n 4. exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
                cout<<"Enter the element to push: ";
                cin>>data;
                push(sp,data);
                break;
            case 2:
                pop(sp);
                break;
            case 3:
                display(sp);
                break;
        }       
    }
    
    return 0;
}