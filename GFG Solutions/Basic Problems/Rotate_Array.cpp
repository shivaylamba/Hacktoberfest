/*
Given an array of size N. The task is to rotate array by D elements where D ≤ N.
Example 1:
Input:
N = 7
Arr[] = {1, 2, 3, 4, 5, 6, 7}
D = 2
Output: 3 4 5 6 7 1 2
Explanation: 
Rotate by 1: [2, 3, 4, 5, 6, 7, 1]
Rotate by 2: [3, 4, 5, 6, 7, 1, 2]
Example 2:
Input:
N = 4
Arr[] = {1, 3, 4, 2}
D = 3
Output: 2 1 3 4
Your Task:
You don't need to read input or print anything. Your task is to complete the function leftRotate() which takes the array of integers arr[], its size n and d as input parameters and rotates arr[] in-place without using any extra memory.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 1000
0 ≤ D ≤ N
*/
//{ Driver Code Starts
//Initial template for C++
/*
Let the array be - 123456789 and k = 4

Step 1 - 12345 6789 ---> 54321 6789

Step 2 - 54321 6789 ---> 54321 9876

Step 3 - 543219876 ---> 678912345

*/
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template for C++
class Solution{   
public:
  // First Approach Time Complexity is O(n)
  //                 Space complexity is O(1)
    void leftRotate(int arr[], int n, int d) {
        // code here
       int i = 0 , j = d-1;
       while(i<j){
           swap(arr[i++],arr[j--]);
       }
       i = d , j = n-1;
       while(i<j){
            swap(arr[i++],arr[j--]);

       }
            i = 0, j = n-1;
       while(i<j){
            swap(arr[i++],arr[j--]);

       }
    }
  // Second Approach Time Complexity is O(nlog(n))
  //                 Space complexity is O(1)
    void rotate(vector<int>& nums, int k) {
        int n =nums.size() ;
   k = k%n;
   reverse(nums.begin(),nums.begin() + (n-k));
   reverse(nums.begin() + (n-k) , nums.end());
   reverse(nums.begin(),nums.end());
    }

  // third Approach Time Complexity is O(n)
  //                 Space complexity is O(n)
     void rotate1(vector<int>& nums, int k) {
        int n =nums.size() ;
        vector<int> temp(n);
       for(int i =0;i<n;i++){
             temp[(i+k)%n] = nums[i];
       }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}