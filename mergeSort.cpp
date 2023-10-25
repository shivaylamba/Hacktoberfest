#include <iostream>
#include <vector>

void merge(std::vector<int>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; ++i)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = array[middle + 1 + j];

    // Merge the temporary arrays back into array[left...right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

int main() {
    std::vector<int> array = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Perform merge sort
    mergeSort(array, 0, array.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
