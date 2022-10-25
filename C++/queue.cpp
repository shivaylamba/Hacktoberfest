#include<bits/stdc++.h>
using namespace std;

struct myQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct myQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct myQueue *q){
    if(q->r==q->size){
        return 1;
    }
    return 0;
}
void enqueue(struct myQueue *q,int val){
    if(isFull(q)){
        cout<<"The Queue is full";
    }
    else{
        q->arr[q->r]=val;
        q->r++;
    }
}
int dequeue(struct myQueue *q){
    if(isEmpty(q)){
        cout<<"The queue is empty";
        return -1;
    }
    else{
        int val=q->arr[q->f];
        q->f++;
        return val;
    }
}
void display(struct myQueue *q){
    if(isEmpty(q)){
        cout<<"Queue is Empty";
    }
    else{
        for(int i=q->f;i<q->r;i++ ){
            cout<<q->arr[i]<<" ";
        }
    }
}

int main(){
    struct myQueue *q=(struct myQueue*)malloc(sizeof(myQueue));
    cout<<"Enter the size of queue: ";
    cin>>q->size;
    q->f=q->r=0;
    q->arr=(int *)malloc(q->size*sizeof(int));
    int n=0;
    int data;
    while(n!=4){
        cout<<"\nEnter the choice:\n 1.Enqueue\n 2. Dequeue\n 3.Display\n 4. exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
                cout<<"Enter the element u want to insert: ";
                cin>>data;
                enqueue(q,data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
        }
    }
    return 0;
}