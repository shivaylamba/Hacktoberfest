#include <iostream>
using namespace std;

void flip(int arr[], int i) {
    int temp, start = 0;
    // Flip the array from start to i
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n) {
    int maxIndex = 0; 
    for (int i = 0; i < n; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex; 
}

void pancakeSort(int *arr, int n) {
   
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int maxIndex = findMax(arr, curr_size); 

        if (maxIndex != curr_size - 1) {
            flip(arr, maxIndex); 
            flip(arr, curr_size - 1);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]); 

    pancakeSort(arr, n);

    cout << "Sorted Array:" << endl; 
    printArray(arr, n); 

    return 0; 
}
