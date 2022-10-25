#include<bits/stdc++.h>
using namespace std;

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        q->r=0;
        q->f=0;
        return 1;
    }
    return 0;
}
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size==(q->f)%q->size){
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        cout<<"Queue is full";
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        if(q->f==-1){
            q->f=0;
        }
    }
}
int dequeue(struct circularQueue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty";
        return -1;
    }
    else{
        int val=q->arr[q->f];
        q->f=(q->f+1)%q->size;
        return val;
    }
}
void display(struct circularQueue *q){
    cout<<"f "<<q->f<<"r "<<q->r<<endl;
  if(isEmpty(q)){
    cout<<"Queue is empty: ";
  }
  else{
    for(int i=q->f;i<=q->r;i++){
        cout<<q->arr[i%q->size]<<" ";
    }
  }
}
int main(){
    struct circularQueue *q=(struct circularQueue*)malloc(sizeof(circularQueue));
    cout<<"Enter the size of queue: ";
    cin>>q->size;
    q->f=-1;
    q->r=-1;
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