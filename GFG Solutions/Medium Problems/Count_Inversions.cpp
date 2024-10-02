/*
Count Inversions
Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Examples:
Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: n = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: n = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Expected Time Complexity: O(nLogn).
Expected Auxiliary Space: O(n).
Constraints:
1 ≤ n ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/
/*
    MOST OPTIMIZED APPROACH  USING MERGE SORT
*/
/*
    NOT OPTIMIZED APPROACH USING NESTED LOOP
Time Complexity: O(n2), For using two nested loops
Auxiliary Space: O(1), No extra space is required
*/
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        long long int count = 0 ;
        for(long long int i = 0 ; i<n-1;i++){
            for(long long int j =i+1;j<n;j++){
                if(arr[i]>arr[j] && i<j) count++;
            }
        }
        return count ;
    }
};