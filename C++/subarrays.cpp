#include<iostream>
using namespace std;

int printallpairs(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<endl;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int arr[]={10,20,30,40,50,60};
    int n=sizeof(arr)/sizeof(int);
    printallpairs(arr,n);
}