#include <iostream>
#include<cmath>
using namespace std;

#define length 50     //defining max length of priority queue
#define left_child_index(i) 2*i+1   // defining index of left child node of a heap
#define right_child_index(i) 2*i+2  // defining index of right child node of a heap
        // defining index of parent node of heap

typedef struct{   //defining struct data type node to store a job along with its priority and time
   string job;
   int priority;
   int time;
}node;

bool Priority(node a, node b){    //defining bool function to check which job is more prior
    if(a.priority<b.priority){    // returns true if job 'b' is more prior
        return false;
    }
    else if(a.priority == b.priority ){
        if(a.time < b.time){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}
 
void node_swap(node* a, node* b){  //defining function to swap to jobs with node data type
    node temp = *a;
        *a = *b;
        *b = temp;
}

void min_heapify(node a[], int i, int size){  //defining min_hepify function 
    int min,l,r;
    l = left_child_index(i);
    r = right_child_index(i);
    if(r<size){
    min = Priority(a[l], a[r] )? (Priority(a[r], a[i]) ? i:r):(Priority(a[l], a[i])? i:l); //using ternary operator to find max of three integers
    }
    if(r>=size){
    min = Priority(a[l], a[i] )?i:l; 
    }
    if(min != i){
        node_swap(&a[min], &a[i]);
        if(2*min+1 <= size){
            min_heapify(a, min, size);
        }
    }
}

void Build_min_heap(node a[], int size){
      //defining build min heap function to construct min heap from scrap
    for( int i= ((size/2)-1); i>=0 ; i-- ){
        min_heapify(a, i, size);
    }
}

node extract_min(node a[],int size){  // defining extract min function
    node min = a[0];
    a[0] = a[size-1];
    size = size -1;
    min_heapify(a, 0, size);
    return min;
}

void queue_print(node a[], int size){   //defining priority queue using min heap 
    Build_min_heap(a, size);            //we take a array of nodes which include job and its priority 
    node store;                         //then we arrange them in min_heap as best rank priority as top of heap
    int t_time =0 ;                     // then we print it out and again construct min heap with the next best prior rank as top
    for(int i=size-1;i>=0;i--){        // then we print all jobs in priority order
       store = extract_min(a,i+1);
       t_time += store.time;
       cout<<store.job<<"  "<<store.priority<<" "<<t_time-store.time+1<<" - "<<t_time<<" "<<endl;
    }
}

int main(){
    //Hard coded input 
    int size =4;  //number of jobs
    node arr[4] = {{"3",1,40},{"4",2,10},{"5",1,25},{"6",2,20}}; //specifics of jobs
    queue_print(arr, size);
}