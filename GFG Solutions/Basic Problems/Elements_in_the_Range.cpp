/*
Given an array arr[] containing positive elements. A and B are two numbers defining a range. The task is to check if the array contains all elements in the given range.

Example 1:

Input: N = 7, A = 2, B = 5
arr[] =  {1, 4, 5, 2, 7, 8, 3}
Output: Yes
Explanation: It has elements between 
range 2-5 i.e 2,3,4,5
Example 2:

Input: N = 7, A = 2, B = 6
arr[] = {1, 4, 5, 2, 7, 8, 3}
Output: No
Explanation: Array does not contain 6.

Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function check_elements() that takes array arr, integer N, integer A, and integer B  as parameters and returns the boolean True if array elements contain all elements in the given range else boolean False.

Note: If the array contains all elements in the given range then driver code outputs Yes otherwise, it outputs No

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ N ≤ 107
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    // Method 1 : (Intuitive)
    // Time complexity: O(n log n) 
// Auxiliary space: O(1)
bool check_elements1(int arr[], int n, int A, int B) {
    if (A > B) {
        return false; // invalid range
    }
 
    for (int i = A; i <= B; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false; // element not found in array
        }
    }
    return true; // all elements in range found in array
}
// Time complexity: O(n) 
// Auxiliary space: O(n)
	bool check_elements(int arr[], int n, int A, int B)
	{
		// Your code goes here
		set<int> ans;
		int count = B-A+1;
		for(int i = 0 ;i<n;i++){
		    if(arr[i] >= A && arr[i]<=B){
                ans.insert(arr[i]);
		    }
		}
		return (ans.size() == count)?1:0;
	}

    // Method 3 : (Best):
    // Time complexity : O(n) 
// Auxiliary space : O(1)
bool check_elements2(int arr[], int n, int A, int B)
{
    //Array should contain atleast B-A+1 elements
    if(n<B-A+1) return false;
    // Range is the no. of elements that are
    // to be checked
    int range = B - A;
 
    // Traversing the array
    for (int i = 0; i < n; i++) {
        // If an element is in range
        if (abs(arr[i]) >= A && abs(arr[i]) <= B) {
            // Negating at index ‘element – A’
            int z = abs(arr[i]) - A;
            if (arr[z] > 0)
                arr[z] = arr[z] * -1;
        }
    }
    // Checking whether elements in range 0-range
    // are negative
    int count = 0;
    for (int i = 0; i <= range && i < n; i++) {
        // Element from range is missing from array
        if (arr[i] > 0)
            return false;
        else
            count++;
    }
    if (count != (range + 1))
        return false;
    // All range elements are present
    return true;
}


		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends