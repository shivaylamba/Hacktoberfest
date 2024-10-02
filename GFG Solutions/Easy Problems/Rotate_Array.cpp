/*
Rotate Array
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 

 

Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
Example 2
Input:
N = 10, D = 3
arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20 
when rotated by 3 elements, it becomes 
8 10 12 14 16 18 20 2 4 6.
Your Task:
You need not print or read anything. You need to complete the function rotateArr() which takes the array, D and N as input parameters and rotates the array by D elements. The array must be modified in-place without using extra space. 
Expected Time Complexity: O(N
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 106
1 <= D <= 106
0 <= arr[i] <= 105
*/
//{ Driver Code Starts
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        // Stop the unneccessary Rotation
        // Avoid Using the Inbuilt Rotate Function
        d%=n;
        int i=0,j=d-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
        i=d;j=n-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
        i=0;j=n-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
    }
};

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        // Stop the unneccessary Rotation
        
        d%=n;
         reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);
    }
};

//{ Driver Code Starts.