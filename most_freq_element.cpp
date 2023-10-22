#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> frequency;
    int mostFrequent = arr[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        if (frequency.find(arr[i]) == frequency.end()) {
            frequency[arr[i]] = 1;
        } else {
            frequency[arr[i]]++;
            if (frequency[arr[i]] > maxCount) {
                maxCount = frequency[arr[i]];
                mostFrequent = arr[i];
            }
        }
    }

    cout << "The most frequent element in the array is: " << mostFrequent << endl;
    cout << "It appears " << maxCount << " times." << endl;

    return 0;
}
