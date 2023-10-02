#include <iostream>

void bubbleSort(int arr[], int n) {
    int temp;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false; // Flag to optimize the algorithm

        // Traverse the array from 0 to n-i-1
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater
            // than the next element
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // Set the flag to indicate a swap occurred
            }
        }

        // If no two elements were swapped in the inner loop,
        // the array is already sorted, so we can break out of the loop early.
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
