#include <iostream>
//code for queue concept

using namespace std;
int queue[100];
int n=100, front=-1,rear=-1;        //intialising array named as queue
void insert(){
    int val;
    if (rear==n-1){         
        cout<<"Queue Overflow"<<endl;       //Queue is already filled
    }
    else{
        if(front==-1)               //condition for insertion
            front=0;
            cout<<"Insert the element in Queue : "<<endl;
            cin>>val;
            rear++;                 
            queue[rear]=val;            //insering element

    }
}
void del(){
    if(front==-1||front>rear){
        cout<<"Queue underflow"<<endl;          //Queue is empty it does not have element to delete
    }
    else{
        cout<<"Element deleted from the Queue: "<<queue[front]<<endl;           //print deleted Element
        front++;
    }
}
void display(){
    if (front==-1){
        cout<<"queue is empty"<<endl;           //Queue is empty it does not have element to print
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";                // queue printing
        }
        cout<<endl;
    }
}

int main()
{
   int ch;
   int val;

   cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do {
    cout<<"Enter your choice : "<<endl;
    cin>>ch;
    switch (ch) {
    case 1: 
        cout<<"how many elements you want to push in a queue";
        cin>>n;
        for(int i=0;i<n;i++)
        {
        insert();           //calling a function
        }


    break;

    case 2: del();              //calling a function
    break;
    case 3: display();      //calling a function
    break;
    case 4: cout<<"Exit"<<endl;         //ending this program
    break;
    default: cout<<"Invalid choice"<<endl;
    }
    } while(ch!=4);
return 0;
}
