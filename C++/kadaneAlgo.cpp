// Kadane's Algorithm is used to find the maximum sum of a subarray
#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorith
int maximumSumSubarray(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(maxEnding, res);
    }
    return res;
}

int main()
{
    int arr[] = {-3, 8, -2, 4, -5, 6};
    int n = 6;
    int ans = maximumSumSubarray(arr, n);
    cout << ans << endl;
    // ans will be 11
}