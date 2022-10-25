//ARRAY AS ADT
#include<bits/stdc++.h>
using namespace std;

struct myArray{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize){
    a->totalSize=tSize;
    a->usedSize=uSize;
    a->ptr= (int *)malloc( tSize*sizeof(int));
}

void setArray(struct myArray *a){
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<a->usedSize;i++){
        cin>>a->ptr[i];
    }
}

void display(struct myArray *a){
    for(int i=0; i<a->usedSize;i++){
        cout<<a->ptr[i]<<" ";
    }
}

int insert(struct myArray *a, int element, int index){
    if(a->totalSize< a->usedSize+1){
        return -1;
    }
    for(int i=a->usedSize;i>=index;i--){
        a->ptr[i]=a->ptr[i-1];
    }
    a->ptr[index]=element;
    a->usedSize++;
    return 1;
}

void deleteIndex(struct myArray *a, int index ){
    for( int i=index; i<a->usedSize-1;i++){
        a->ptr[i]=a->ptr[i+1];
    }
    a->usedSize--;
}

int main(){
    struct myArray digits;
    int t, u;
    cout<<"Enter the total size of array: ";
    cin>>t;
    cout<<"Enter the size to be used: ";
    cin>>u;
    createArray(&digits, t,u);
    setArray(&digits);
    display(&digits);
    cout<<endl;
    insert(&digits, 9, 3);
    display(&digits);
    deleteIndex(&digits, 4);
    cout<<endl;
    display(&digits);

    return 0;
}