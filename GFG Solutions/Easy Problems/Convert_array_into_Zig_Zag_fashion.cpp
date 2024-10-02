/*
Convert array into Zig-Zag fashion
Given an array arr of distinct elements of size n, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 
arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 
Note: Modify the given arr[] only, If your transformation is correct, the output will be 1 else the output will be 0.
Examples
Input: n = 7, arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
Input: n = 4, arr[] = {1, 4, 3, 2}
Output: 1 4 2 3
Explanation: 1 < 4 > 2 < 3
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 <= n <= 106
0 <= arri <= 109
*/
/*
        OPTMIZED APPROACH
    Time Complexity O(n)
    Time Complexity O(1)
*/
class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        // code here
        int f  =1;
        int i = 0 , j = 1;
        while(j<n){
            if((arr[i]>arr[j] && f==1 )  || (f==0 && arr[i]<arr[j])) { swap(arr[i],arr[j]);    }
                f = f^1;
            i++;j++;
        }
    }
};
/*
    Convert array into Zig-Zag fashion Using Sorting
    Time Complexity O(n*log(n))
    Time Complexity O(1)
*/
void zigZag(vector<int>& arr, int N)
{
    // sort the array by using the sort function
    sort(arr.begin(), arr.end());
    // traverse the array from 1 to N -1
    for (int i = 1; i < N - 1; i += 2) {
        // swap the current element with the next element
        swap(arr[i], arr[i + 1]);
    }
    // print the complete array
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return;
}