//binary search recursive
#include <iostream>
using namespace std;

int bs(int arr[], int low, int high, int key){
    if(high>=low){

    int mid=(low+high)/2;
    if(key==arr[mid]){
        return mid;
    }
    else if(key>arr[mid]){
        return bs(arr, mid+1, high, key);
    }
    else{
        return bs(arr,low, mid-1, key);
    }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search: ";
    int key;
    cin>>key;
    int ans =bs(arr,0,n-1,key);
    if(ans==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index: "<<ans+1<<endl;
    }
    return 0;
}