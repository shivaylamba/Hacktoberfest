/*
Merge Sort :
Sorting algorithm that is based on the Divide and Conquer.
In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.
*/
#include<iostream>
using namespace std;

// arr: array to be merged into | l_arr: left array | r_arr: right array | ls: left array size | rs: right array size
void merge(int *arr, int *l_arr, int ls, int *r_arr, int rs) {

    int i=0,j=0,k=0;

    while(i < ls && j < rs) {
        if(l_arr[i] <= r_arr[j]) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    while(i < ls) {
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while(j < rs) {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

// arr: array to be divided into left and right | n: size of the array 
void mergeSort(int *arr, int n) {
    if(n < 2) return;

    int ls = n/2;
    int rs = n-ls;

    int l_arr[ls], r_arr[rs], i;
    
    for(i=0; i<ls; i++) l_arr[i] = arr[i];
    for(i=ls; i<n; i++) r_arr[i-ls] = arr[i];

    mergeSort(l_arr, ls);
    mergeSort(r_arr, rs);
    merge(arr,l_arr,ls,r_arr,rs);
}

int main() {
    int a[] = {5,3,4,1,2,0};
    int size = sizeof(a)/sizeof(a[0]);
    mergeSort(a, size);
    for(int i=0; i<size; i++) cout<<a[i];
    return 0;
}
