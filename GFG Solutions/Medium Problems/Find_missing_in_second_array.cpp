/*
Find missing in second array
Given two arrays a of size n and b of size m, the task is to find numbers which are present in the first array, but not present in the second array.
Example 1:
Input: 
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 10}
b[] = {2, 3, 1, 0, 5}
Output: 
4 10
Explanation: 
4 and 10 are present in first array, but not in second array.
Example 2:
Input: 
n = 5, m = 5
a[] = {4, 3, 5, 9, 11}
b[] = {4, 9, 3, 11, 10}
Output: 
5  
Explanation: 
Second array does not contain element 5.
Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findMissing() that takes array a, array b, integer n, and integer m as parameters and returns an array that contains the missing elements and the order of the elements should be the same as they are in array a.
Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(m).
Constraints:
1 ≤ n, m ≤ 105
-109 ≤ A[i], B[i] ≤ 109
*/
/*
Most Optimized Approach
 Time Complexity O(n+m);
 Space Complexity O(n)
*/
class Solution{
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    // making an unoredered_map to stored the elements
	    unordered_map<int,int> f;
	    for(int i=0;i<m;i++){
	        f[b[i]]++;
	    }
	    vector<int> ans;
	    // iterate the array a and the search the element in the unordered_map
	    // if its not present than push the element in the answer array
	    for(int i=0;i<n;i++){
	        // check the element is present or not in the unordered_map
	        if(f.find(a[i]) == f.end()){
	            ans.push_back(a[i]);
	        }
	    }
	    // return the anwer array
	    return ans;
	} 
};
/*
Other Optimized Approach but Not Recommended (using Double Loop or Recursion)
 Time Complexity O(n*m);
 Space Complexity O(1)
*/
	