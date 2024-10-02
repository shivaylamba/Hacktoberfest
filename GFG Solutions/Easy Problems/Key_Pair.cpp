/*
Key Pair
Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

Example 1:

Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
Example 2:

Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and returns a boolean denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 105
*/
//User function template for C++
/*
        using Hashing:
    Time Complexity: O(N), Time complexity for sorting the array
    Auxiliary Space: O(N)
*/
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
        unordered_set<int> s;
        for(int i  =0  ; i<n;i++){
            int temp = x  -arr[i];
            if(s.find(temp)!=s.end()){
                return 1;
            }
            s.insert(arr[i]);
        }
	    return 0;
	}
};
/*
        Sorting and Two-Pointers technique:
    Time Complexity: O(NlogN), Time complexity for sorting the array
    Auxiliary Space: O(1)
*/
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr,arr+n);
	    int i =0 , j = n-1;
	    while(i<j){
	        int sum = arr[i]+arr[j];
	        if(sum==x) return 1;
	        else if(sum>x) j--;
	        else i++;
	    }
	    return 0;
	}
};