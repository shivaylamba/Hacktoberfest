#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum element in the array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Counting sort used by radix sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] so that count[i] now contains actual positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted output to arr
    arr = output;
}

// Main radix sort function
void radixSort(vector<int>& arr) {
    int maxNum = getMax(arr);

    // Apply counting sort for each digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr);

    cout << "\nSorted array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
