/*
Swap the array elements
Given an array arr of n positive integers. The task is to swap every ith element 
of the array with (i+2)th element.
Example 1:
Input:
n = 3
arr[] = 1 2 3
Output:
3 2 1
Explanation:
Swapping 1 and 3, makes the array 3 2 1. There is only one swap possible in this array.
Example 2:

Input:
n = 5
arr[] = 1 2 3 4 5
Output:
3 4 5 2 1
Explanation:
Swapping 1 and 3, makes the array 3 2 1 4 5.
Now, swapping 2 and 4, makes the array 3 4 1 2 5. 
Again,swapping 1 and 5, makes the array 3 4 5 2 1.
Your Task:
Your task is to complete the function swapElements(), which should swap each ith element with 
(i+2)th element.
Expected Time Complexity: O(n)
Expected Auxilary Space: O(1)
Constraints:
1 <= n <= 106
0 <= arri <= 109
*/
//{ Driver Code Starts
//Initial Template for C++
#include <iostream>
using namespace std;
// } Driver Code Ends
//User function Template for C++
/*Function to swap array elements
* arr : array input
* n : number of elements in array
*/
class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Your code here
        for(int i=0 ; i< n-2;i++){
            swap(arr[i],arr[i+2]);
        }
    }
};
//{ Driver Code Starts.
// Driver code to test swapElements
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution obj;
        // calling function to swap the array swap elements
	    obj.swapElements(arr, n);
	    
	    // Printing the modified array
	    for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends