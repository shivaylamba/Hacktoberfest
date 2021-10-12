#include <iostream>

using namespace std;

// A recursive Linear search function. It returns location of x in given array arr[l..r] is present, 
// otherwise -1  

int LinearSearch(int arr[], int n, int x) { 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int x,i, position;
    cin>> x ;  //Input number
    int size = sizeof(arr) / sizeof(arr[0]); 

    position = LinearSearch(arr,size,x);

     (position == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << position;    

    return 0;
}
