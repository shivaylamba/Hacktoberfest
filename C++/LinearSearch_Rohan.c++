#include<iostream>

using namespace std;

int main(){
    // Taking the size of the array as input
    int n;
    cout<<"Enter the size of the array->";
    cin>>n;

    // Declaring the array
    int arr[n];

    // Taking the array as input
    cout<<"Now enter the array:"<<endl;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    // Taking the element user wants to find as input
    int elem;
    cout<<"Enter the element you want to search->";
    cin>>elem;

    // Declaring a flag variable, if flag=0 => element not found; if flag=1 => element found
    int flag=0, index=-1;

    // Traversing the array
    for(int i=0; i<n; ++i){
        if(arr[i]==elem){
            flag=1;
            index=i;
        }
    }

    // Checking if the elemene is found or not
    if(flag==1){
        cout<<"The element is found and it is at the "<<index<<"-th index"<<endl;
    }
    else{
        cout<<"The element is not found"<<endl;
    }
    return 0;
}