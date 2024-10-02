#include<bits/stdc++.h>
using namespace std;
void getArray(int *arr,int n){
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int arr[],int n){
    bool succes ;   // to check the successful swapping 
    for (int i = 0;i<n-1;i++){
            succes = false;
      for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){  // if the ith element is greater than (i+1)th element than swap
            swap(arr[j],arr[j+1]);
            succes = true;
        }
      }
      if(succes==false){   // if didnt swap successfully than break the loop
        break;            // Help to decreasing no of passes
      }
      cout<<"Pass->"<<i+1<<":"<<endl;
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
    bubbleSort(arr,n);
return 0;
}