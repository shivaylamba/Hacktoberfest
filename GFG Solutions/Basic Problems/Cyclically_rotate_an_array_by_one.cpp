/*
Cyclically rotate an array by one
Stuck on a problem? Level up with 35% Off on premium GfG Courses and master coding! 
banne
Given an array, rotate the array by one position in clock-wise direction.
Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes the array A[] and its size N as inputs and modify the array in place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1<=N<=105
0<=a[i]<=105
*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends
//User function Template for C++
void rotate(int arr[], int n)
{
    int ld = arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i]  = arr[i-1];
     }
     arr[0] =ld;
    
}