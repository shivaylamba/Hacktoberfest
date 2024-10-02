#include<bits/stdc++.h>
using namespace std;
void getArray(int *arr,int n){
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void selectionSort(int arr[],int n){
    for (int i = 0;i < n-1;i++){
       int minidx = i;
       for(int j=i+1;j<n;j++){
        if(arr[minidx]>arr[j]){
            minidx = j;    // save minimum element index in minidx
        }
       }
       swap(arr[minidx],arr[i]);  // swap minimum element with the ith element
       cout<<"Pass->"<<i+1<<":"<<endl;  // this Showing the number of passes
    getArray(arr,n);
    cout<<endl;
}
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before Selection Sort :"<<endl;
        getArray(arr,n);
    cout<<endl<<"After the Selection Sort :"<<endl;
    selectionSort(arr,n);
return 0;
}