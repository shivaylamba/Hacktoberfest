/*
------------------Largest Sum Contiguous Subarray (Kadane’s Algorithm)-----------------------------
=> Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within a 
   arr[] with the largest sum. 
=> The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum 
   sum contiguous subarray ending at current index and a variable max_so_far stores the maximum 
   sum of contiguous subarray found so far, Everytime there is a positive-sum value in 
   max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.

********Pseudocode of Kadane’s algorithm:********
=> Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0
=> Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

Lets take the example: {-2, -3, 4, -1, -2, 1, 5, -3}
Note: in the image max_so_far is represented by Max_Sum and max_ending_here by Curr_Sum

=>For i=0,  a[0] =  -2
    - max_ending_here = max_ending_here + (-2)
    - Set max_ending_here = 0 because max_ending_here < 0
    - and set max_so_far = -2

=> For i=1,  a[1] =  -3
    - max_ending_here = max_ending_here + (-3)
    - Since max_ending_here = -3 and max_so_far = -2, max_so_far will remain -2
    - Set max_ending_here = 0 because max_ending_here < 0

=>For i=2,  a[2] =  4
    - max_ending_here = max_ending_here + (4)
    - max_ending_here = 4
    - max_so_far is updated to 4 because max_ending_here greater than max_so_far which was -2 till now

=> For i=3,  a[3] =  -1
    - max_ending_here = max_ending_here + (-1)
    - max_ending_here = 3

=>For i=4,  a[4] =  -2
    - max_ending_here = max_ending_here + (-2)
    - max_ending_here = 1

=>For i=5,  a[5] =  1
    - max_ending_here = max_ending_here + (1)
    - max_ending_here = 2

=>For i=6,  a[6] =  5
    - max_ending_here = max_ending_here + (5)
    - max_ending_here =
    - max_so_far is updated to 7 because max_ending_here is greater than max_so_far

=>For i=7,  a[7] =  -3
    - max_ending_here = max_ending_here + (-3)
    - max_ending_here = 4

=>Follow the below steps to Implement the idea:
 - Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
 - Run a for loop from 0 to N-1 and for each index i: 
        -Add the arr[i] to max_ending_here.
        -If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
        -If max_ending_here < 0 then update max_ending_here = 0
Return max_so_far
Below is the Implementation of the above approach.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){      
        // Your code here
        long long max_for =INT_MIN , max_ending_here = 0;
        for(int i=0;i<n;i++){
            max_ending_here+=arr[i];
            if(max_for< max_ending_here)
                max_for = max_ending_here;
            
            if(max_ending_here < 0)
                max_ending_here =0;
        }
        return max_for;
    }
};
//{ Driver Code Starts.
int main()
{
    int t,n;
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        cin>>n; //input size of array
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;       
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends