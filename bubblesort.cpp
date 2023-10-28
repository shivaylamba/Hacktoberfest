#include<iostream>

void bubbleSort(int arr[], int n) {
   for(int i = 0; i < n-1; i++) {     
       for (int j = 0; j < n-i-1; j++) { 
           if (arr[j] > arr[j+1]) {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }
}

void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++)
       std::cout << arr[i] << " ";
   std::cout << std::endl;
}

int main() {
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr, n);
   std::cout << "Sorted array: \n";
   printArray(arr, n);
   return 0;
}
