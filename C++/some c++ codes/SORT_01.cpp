#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};

    sort(arr.begin(), arr.end());

    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
