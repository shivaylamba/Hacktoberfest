/*
Given an sorted array A of size N. Find number of elements which are less than or equal to given element X.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countOfElements() which takes the array A[], its size N and an integer X as inputs and returns the number of elements which are less than or equal to given element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Ai <= 105
0 <= X <= 105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countOfElements(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        cin >> x;

        cout << countOfElements(arr, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends


int countOfElements(int arr[], int n, int x) 
{
    int count = 0;
    if(x==0){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(arr[i] <=x){
            count++;
        }
        else{
            break;
        }
    }
    return count ;
}