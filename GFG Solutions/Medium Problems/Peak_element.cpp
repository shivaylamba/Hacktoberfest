/*
Peak element
Given an 0-indexed array of integers arr[] of size n, find its peak element. An element is 
considered to be peak if it's value is greater than or equal to the values of its adjacent 
elements (if they exist). The array is guaranteed to be in ascending order before the peak 
element and in descending order after it.
Note: The output will be 1 if the index returned by your function is correct; otherwise, 
it will be 0.
Example 1:
Input: 
n = 3
arr[] = {1, 2, 3}
Peak Element's Index: 2
Output: 1
Explanation: 
If the index returned is 2, then the output printed will be 1. 
Since arr[2] = 3 is greater than its adjacent elements, and 
there is no element after it, we can consider it as a peak 
element. No other index satisfies the same property.
Example 2:
Input:
n = 3
arr[] = {3, 4, 2}
Peak Element's Index: 1
Output: 1
Explanation: 
If the index returned is 1, then the output printed will be 1.
Since arr[1] = 4 is greater than its adjacent elements, and
there is no element after it, we can consider it as a peak
element. No other index satisfies the same property.
Your Task:
You don't have to read input or print anything. Complete the function peakElement() which 
takes the array arr[] and its size n as input parameters and return the index of the peak element.
Expected Time Complexity: O( log(n) ).
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int i=0 , j = n-1;
       int ans = -1 ;
       int mid = i + (j-i)/2;
       while(i<j){
           if(arr[mid] < arr[mid+1]){
                i = mid+1;
           }
           else{
                j = mid;
           }
           mid = i+(j-i)/2;
       }
       return i;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends