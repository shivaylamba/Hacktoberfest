/*
Maximum product subset of an array
Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10
*/
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
         if(arr.size()==1) return arr[0];
        long long int prod=1;
        int zero=0,non_zero=0,maxi=INT_MIN;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0){
                prod=(prod*arr[i])%1000000007;
                non_zero=1;
            }
            else{ zero=1;}
            if(arr[i]<0 and arr[i]>maxi)
            maxi=arr[i];
        }
        if(non_zero!=1) return 0;
        if(arr.size()==2 and zero==1 and prod<0) return 0;
        if(prod<0) prod/=maxi;
        return prod;
    }
};