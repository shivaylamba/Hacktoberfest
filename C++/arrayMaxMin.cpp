#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Given array is: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    for(int i=0; i<n; i++){
        maxNum = max(maxNum,arr[i]);
        minNum = min(minNum,arr[i]);
    }
    cout << "Maximum and Minimum elements of array are: " << maxNum << " " << minNum << endl;
}
