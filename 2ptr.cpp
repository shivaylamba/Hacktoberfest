#include <bits/stdc++.h>
 
using namespace std;
 
bool isPairSum(int A[], int N, int X)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (i == j)
                continue;
 

            if (A[i] + A[j] == X)
                return true;
 

            if (A[i] + A[j] > X)
                break;
        }
    }
 
    // No pair found with given sum.
    return false;
}
 
int main()
{
    int arr[] = { 2, 3, 5, 8, 9, 10, 11 };
    int val = 17;
    int arrSize = *(&arr + 1) - arr;
    sort(arr, arr + arrSize); // Sort the array
    // Function call
    cout << isPairSum(arr, arrSize, val);
 
    return 0;
}
