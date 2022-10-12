// Count Inversions

/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. 
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.


Time Complexity: O(NLogN).
Auxiliary Space: O(N).

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge (long long  arr[],long long temp[],long long l,long long mid, long long r)
    {    
        long long  start=l;
        long long  count=0;
        long long j=mid+1,k=l;
        while(  (l<=mid) &&   (r>=j) )
        {
            if(arr[l]<=arr[j])
                temp[k++]=arr[l++];
            else
            {
                count+=  mid+1-l;
                temp[k++]=arr[j++];
            }
        }
        while(l<=mid)
            temp[k++]=arr[l++];
            
        while(j<=r)
            temp[k++]=arr[j++];
       
        for(long long p=start;p<=r;p++)
            arr[p]=temp[p];
     
        return count;
    }
    
    long long int mergesort(long long  arr[],long long  temp[],long long  l,long long  r)
    {
        long long  count=0,mid;
        if(l<r)
        {
            long long mid=(l+r)/2;
            count += mergesort( arr,temp, l, mid);
            count += mergesort(arr,temp, mid+1, r);
            count += merge ( arr,temp,l, mid, r);
        }
        return count;
    }
    
    
    long long int inversionCount(long long temp[], long long N)
    {
        // Your Code Here
        long long arr[N];
        
        return mergesort(temp, arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends