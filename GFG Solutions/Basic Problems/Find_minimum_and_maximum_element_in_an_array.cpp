/*
Find minimum and maximum element in an array
Your Task:  
You don't need to read input or print anything. Your task is to complete the function getMinMax() which takes the array A[] and its size N as inputs and returns the minimum and maximum element of the array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 Constraints:
1 <= N <= 105
1 <= Ai <=1012
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<long long, long long> getMinMax(long long a[], int n) ;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends
pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long  ,long long > p;
    long long int maxa = -9999999;
    long long int mina = 9999999;
    for(int i=0;i<n;i++){
        maxa = max(maxa,a[i]);
        mina = min(mina ,a[i]);
    }
    p.first =mina;
    p.second = maxa;
    return p;
}