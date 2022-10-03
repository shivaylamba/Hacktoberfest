#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
    int temp,j;
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>-1 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
    cout << arr[i] << " "; 
    cout << endl;
}
}
int main() {
int arr[]={ 12, 11, 13, 5, 6 };
int n=sizeof(arr)/sizeof(arr[0]);
insertionsort(arr,n);
printarr(arr,n);
	return 0;
}

->Inserting an element in a sorted array at a sorted position.
->no. of passes-o(n-1);
->no. of swaps o(n^2)
->no. of comparisionso(n^2)
-> Intermediate or one or two pass will not give any useful result.
-> In array we have to shift ele but in LL no need to shift.so, insertion sort is more compatible with LL.
->Adaptive (by nature)
->Best case if the arr is sorted in asc order -o(n)
->worst case if sorted in desc order o(n^2)
->stable
