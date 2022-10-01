#include<iostream>
using namespace std;

int swap(int arr[],int a,int b){
    int c=arr[a];
    arr[a]=arr[b];
    arr[b]=c;
}
int print(int arr[],int n){
    cout<<"you array :";
    for(int i=0;i<n;i++){
        
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"end the world"<<endl;
    int arr[6]={1,2,3,4,5,6};
    print(arr,6);
    int n=6;
    for(int i=0;i<6;i++){
        if(i>n-1){
            swap(arr,i,n-1);
        }
        n--;
    }
    print(arr,6);
    
}