/*
Inverse Permutation--
An inverse permutation is a permutation which you will get by inserting position of an element at the position specified by the element value in the array */


#include <bits/stdc++.h>
using namespace std;

void inversePermutation(int arr[], int size) {


int arr2[size];

for (int i = 0; i < size; i++)
	arr2[arr[i] - 1] = i + 1;

for (int i = 0; i < size; i++)
	cout << arr2[i] << " ";
}

// Driver program to test above function
int main() {

     int arr[] = {2, 3, 4, 5, 1};
     int size = sizeof(arr) / sizeof(arr[0]);
     inversePermutation(arr, size);

return 0;
}
