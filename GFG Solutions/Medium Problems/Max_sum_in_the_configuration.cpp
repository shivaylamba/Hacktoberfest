/*
Max sum in the configuration
Given an integer array(0-based indexing) a of size n. Your task is to return the maximum value of the sum of i*a[i] for all 0<= i <=n-1, where a[i] is the element at index i in the array. The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.

Example 1:

Input: n = 4, a[] = {8, 3, 1, 2}
Output: 29
Explanation: All the configurations possible by rotating the elements are:
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11, so the maximum sum will be 29.
Example 2:

Input: n = 3, a[] = {1, 2, 3}
Output: 8
Explanation: All the configurations possible by rotating the elements are:
1 2 3 here sum is 1*0+2*1+3*2 = 8
3 1 2 here sum is 3*0+1*1+2*2 = 5
2 3 1 here sum is 2*0+3*1+1*2 = 5, so the maximum sum will be 8.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1<=n<=105
1<=a[]<=106
*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=a[i];
        }
        
        long long initial=0, max=0;
        for(long long i=0;i<n;i++){
            initial+=i*a[i];
        }
        max=initial;
        
        for(long long i=1;i<n;i++){
            long long next=initial - (sum-a[i-1]) + 1LL*(n-1)*a[i-1];
            initial=next;
            if(max<initial){
                max=initial;
            }
        }
        return max;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        Your code here
        int ans = INT_MIN;
        for(int i = 0 ; i<n;i++){
            int sum =0 ;
            for(int j=0;j<n;j++){
                int k = (j+i)%n;
                sum+= k*a[j];
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};