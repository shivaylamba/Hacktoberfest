/*
Sort an array of 0s, 1s and 2s
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
    void sort012_switch(int a[], int n)
    {
        // code here 
        int st =0 ,en = n-1;
        int mid =0;
        while(mid<=en){
            switch(a[mid]){
                
             case 0:
                swap(a[mid],a[st]);
                st++;
                mid++;
                break;
           case 2:
                swap(a[mid],a[en]);
                en--;
               break;
            case 1:
                mid++;
                break;
        }
        }
        // sort(a,a+n);
    }
    void sort012_elseif(int arr[], int n) {
 int s = 0 , en = n-1 , mid =0;
 while(mid<=en){
     if(arr[mid]==0){
         swap(arr[mid],arr[s]);
         s++;
         mid++;
     }
     else if(arr[mid]==2){
         swap(arr[mid],arr[en]);
         en--;
     }
     else{
         mid++;
     }
 }
}
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012_switch(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends