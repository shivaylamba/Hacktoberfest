// Date:- 2/10/2023
// Kadane Algorithm in C++

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to store information about a subarray
struct Subarray {
    int start;  // Starting index of the subarray
    int end;    // Ending index of the subarray
    int sum;    // Sum of the subarray
};

/**
 * Kadane's Algorithm for finding the maximum subarray sum.
 *
 * @param arr The input array.
 * @return Subarray structure representing the maximum subarray sum and its indices.
 */
Subarray kadane_algorithm(const vector<int>& arr) {
    Subarray current;
    current.sum = INT_MIN;
    Subarray max;
    max.sum = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        // If current sum is negative, start a new subarray
        if (current.sum < 0) {
            current.start = i;
            current.end = i;
            current.sum = arr[i];
        } else {
            // Extend the current subarray
            current.end = i;
            current.sum += arr[i];
        }

        // Update max if current sum is greater
        if (current.sum > max.sum) {
            max = current;
        }
    }

    return max;
}

int main() {
    int num_elements;
    cout << "Enter the number of elements: ";
    cin >> num_elements;

    vector<int> input_list;
    cout << "Enter the elements, one by one:" << endl;
    for (int i = 0; i < num_elements; i++) {
        int element;
        cin >> element;
        input_list.push_back(element);
    }

    Subarray max_subarray = kadane_algorithm(input_list);

    cout << "Maximum Subarray Sum: " << max_subarray.sum << endl;
    cout << "Subarray Start Index: " << max_subarray.start << endl;
    cout << "Subarray End Index: " << max_subarray.end << endl;

    return 0;
}
