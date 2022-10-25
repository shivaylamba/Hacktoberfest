#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            //swap arr[i] and arr[j]
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    //swap a[low] and a[j]
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quickSort(int arr[], int low, int high){
    int partitionIndex;  //index of pivot after partition
    if(low<high){
        partitionIndex=partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);    //sort left subarr
        quickSort(arr, partitionIndex+1,high); //sort right subarr
    }
}
int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    display(arr,n);
    quickSort(arr,0, n-1);
    display(arr,n);

    return 0;
}