/*
Minimum element in a sorted and rotated array
A sorted(in ascending order) array arr[ ] of size n with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Examples:

Input:
n = 5, arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1
Explanation: 1 is the minimum element in the array.
Input:
n = 7, arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5
Explanation: Here 5 is the minimum element.
Expected Time Complexity: O(log n).
Expected Auxiliary Space: O(log n).

Constraints:
1 ≤ n ≤ 100000
1 ≤ arr[i] ≤ 1000000
*/
class Solution {
  public:
    int findMin(int arr[], int n) {
        // complete the function here
        int i = 0  , j =  n-1;
        int mid ;
         while(i<j){
             mid = i+ (j-i)/2;
             if(arr[i]<=arr[j]) return arr[i];
             if(arr[i]>arr[mid]) j = mid;
             else  i = mid+1;
         }
         return (arr[i]<=arr[j])?arr[i]:-1;
    }
};