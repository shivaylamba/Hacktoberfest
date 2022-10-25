#include<iostream>
using namespace std;
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr[], int mid, int low, int high){
    int i, j, k, temparr[100];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid &&j<=high){
        if(arr[i]<arr[j]){
            temparr[k]=arr[i];
            i++;
            k++;
        }
        else{
            temparr[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temparr[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        temparr[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low; i<=high;i++){
        arr[i]=temparr[i];
    }
}
void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(arr,low, mid);
        mergeSort(arr, mid+1,high);
        merge(arr,mid, low, high);
    }
}

int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    display(arr,n);
    mergeSort(arr,0,n-1);
    display(arr,n);
    return 0;
}