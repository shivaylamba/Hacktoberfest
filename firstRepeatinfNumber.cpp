//C++ program to find first repeating element in array
//using two pointer method
#include <iostream>
using namespace std;
void printFirstRepeating(int arr[], int n){
    int low=0;
    int high=0;
    while (low<high){
        if(arr[low] < arr[high] )
            high--;
        else if( arr[high] > arr[low] ) 
            low++;
        else
            cout<<arr[low]<<"endl";
}

//Driver code
int main(){
    int arr[]={10, 5, 3, 4, 3, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printFirstRepeating(arr, n);
    return 0;
}