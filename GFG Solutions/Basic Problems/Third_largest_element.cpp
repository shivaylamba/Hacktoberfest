/*
Your Task:
Complete the function thirdLargest() which takes the array a[] and the size of the 
array, n, as input parameters and returns the third largest element in the array. 
It return -1 if there are less than 3 elements in the given array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
    int max1 =-9999999;
    int max2 =-9999999;
    int max3 =-9999999;
    if(n<3){
        return -1;
    }
    for(int i=0;i<n;i++){
        max1 = max(max1 ,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]!=max1){
            max2 =max(max2 ,a[i]);
        }
    }
        for(int i=0;i<n;i++){
        if(a[i]!=max1 && a[i]!= max2){
            max3 =max(max3 ,a[i]);
        }
    }
    if(max2 == 9999999 || max1 == 9999999 || max3 == 9999999){
        return -1;
        }
   else{
       return max3;
   }
    }

};

//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends