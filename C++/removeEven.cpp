// Problem Statement
//Given an array, remove all even integers from it.
//Implement this solution in C++ and see if it runs without an error. 
//Implement a function removeEven( int *& Arr, int size ) which takes
//an array arr and its size and removes all the even elements from a given array.

//Input :
//An array with integers and its size

// Note: The array passed to the function has been created dynamically.

//Output 
//An array with only odd integers

//Sample Input 
//[1,2,4,5,10,6,3]

//Sample Output 
//[1,5,3]


//-----------------------------------------------------------------
//My code:
#include<iostream>
using namespace std;
int * removeEven( int *& Arr, int size ) {
    int j;
    for(int i = 0;i < size; i++)
    {
        if (Arr[i] % 2 != 0){
            Arr[j] = Arr[i];
            j++;
        }
    }
  // Write your code here
  return Arr;
}

int main(){
  int * arr;      // declaring array
  arr = new int[10];   // memory allocation
  cout << "Before remove even: "; 
  for ( int i = 0; i < 10; i++ )
  {
    arr[i] = i;      // assigning values
    cout << arr[i] << " ";
  }
  cout << endl;
  arr = removeEven(arr,10);   // calling removeEven
  cout << "After remove even: ";
  for ( int i = 0; i < 5; i++ )
  {
    cout << arr[i] << " ";    // prinitng array
  }
  delete [] arr;  // deleting allocated memory
  return 0;
}
