#include <iostream>
using namespace std;

void swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}

void heapify(int arr[],int size,int selected){
  int largest = selected;
  int left = 2*selected+1;
  int right = 2*selected+2;
  if(left<size && arr[largest]<arr[left]){
    largest = left;
  }
  if(right<size && arr[largest]<arr[right]){
    largest = right;
  }
  if(largest != selected){
    swap(arr[largest],arr[selected]);
    heapify(arr,size,largest);
  }
}

void heap_sort(int arr[],int size){
  for(int i=size/2-1;i>=0;i--){
    heapify(arr,size,i);
  }
  for(int i=size-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}

int main(){
  int arr[] = {1,-2,9,5,3,1,0,120129102,-110021,0};
  int size = sizeof(arr)/sizeof(arr[0]);
  heap_sort(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
}
