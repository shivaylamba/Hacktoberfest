/*
Given an array A[] of N elements. The task is to count number of even and odd elements in the array.

Example:

Input:
N = 5
A[] = 1 2 3 4 5
Output:
3 2
Explanation:
There are 3 odd elements (1, 3, 5)
and 2 even elements (2 and 4).
Your Task:
Your task is to complete the function countOddEven() which should print number of odd and number of even elements in a single line seperated by space.
Print a newline at the end of output.

Constraints:
1 <= N <= 106
1 <= Ai <= 106
*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    /*Function to count even and odd elements in the array
    * arr : Array with its elements
    * sizeof_array : number of array elements
    * countOdd : variable to count number of odd elements
    * countEven : variable to count number of even elements
    */
    void countOddEven(int arr[], int n)
    {
        
        // your code here
        int even = 0 , odd = 0 ;
        for(int i = 0 ; i<n;i++){
        if(arr[i]%2==0)even++;
        else odd++;
        }
        cout<<odd<<" "<<even<<endl;
    }
};

//{ Driver Code Starts.
int main() {
	
	// Testcase input
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int sizeof_array;
	    cin >> sizeof_array;
	    
	    int arr[sizeof_array];
	    
	    // Array elements input
	    for(int i = 0; i < sizeof_array; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    // Calling function to count even and odd
	    ob.countOddEven(arr, sizeof_array);
	    
	}
	
	return 0;
}
// } Driver Code Ends