#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int j,int n){

     if(n==1){
         return ;
     }
     if(j==n-1){
         return bubbleSort(arr,0,n-1);
     }

     if(arr[j]>arr[j+1]){
         swap(arr[j],arr[j+1]);
     }
     return bubbleSort(arr,j+1,n);
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }


    return 0;
}
