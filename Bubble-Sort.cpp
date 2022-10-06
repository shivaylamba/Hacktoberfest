/*
    This program demonstrates Bubble Sort
    Bubble sort is one of the simplest sorting algorithms.
*/

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0; i<=n-2; i++) {
        for(int j=0; j<=n-i-2; j++) {
          if(arr[j]>arr[j+1]) { // to sort in ascending order.
            // if you have to sort in Descending order, use arr[j] <arr[j+1]
              int t=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=t;
          }
     }
}
  
void display(int arr[], int n) {
 for(int i=0; i<n; i++)
   cout<<arr[i]<<" ";
  cout<<endl;
}
  
int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++) 
    cin>>arr[i];
  display(arr, n); // before sorting
  bubbleSort(arr, n); // sorting
  display(arr, n); // after sorting
 return 0; 
}
