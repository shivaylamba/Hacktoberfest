// Trapping Rain Water

/*
Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 


Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10


Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.


Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.


The Time Complexity of the below algorithm is
Time Complexity : O(N)

Space Complexity of the below algorithm is 
Space Complexity : O(N);

Where N is the size of the array
*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long water=0; 
        int lmax[n], rmax[n], j, i;
        
        lmax[0] = arr[0];
        for(i=1; i<n; i++)
            lmax[i] = max(lmax[i-1], arr[i]);
            
        rmax[n-1] = arr[n-1];
        for(i=n-2; i>=0; i--)
            rmax[i] = max(rmax[i+1], arr[i]);
            
        for(i=1; i<n-1; i++)
        {
            water = water + min(lmax[i], rmax[i])-arr[i];
        }
        
        // leaving the first and the last index as they can not accomodate the water
        
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends