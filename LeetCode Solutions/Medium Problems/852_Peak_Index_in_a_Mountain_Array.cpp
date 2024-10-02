/*
852. Peak Index in a Mountain Array
Medium
Topics
Companies
An array arr is a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st =0;
        int en =  arr.size() -1 ;
        int mid = st+ (en-st)/2;
        while(st<en){
            if(arr[mid]<arr[mid+1]){
                st =mid+1;
            }
            else{
                en =mid;
            }
             mid = st+ (en-st)/2;
        }
        return st;
    }
};