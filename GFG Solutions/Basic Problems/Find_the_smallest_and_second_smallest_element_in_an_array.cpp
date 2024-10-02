/*
Your Task:  
You don't need to read input or print anything. Your task is to complete the 
function minAnd2ndMin() which takes the array A[] and its size N as inputs 
and returns a vector containing the smallest and second smallest 
element if possible, else return {-1,-1}.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1<=N<=105
1<=A[i]<=105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> minAnd2ndMin(int a[], int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
vector<int> minAnd2ndMin(int a[], int n) {
    int mina = 9999;
    int smina = 9998;
    vector<int> ans;
    for(int i=0;i<n;i++){
        mina = min(mina ,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]!=mina){
            smina =min(smina ,a[i]);
        }
    }
    ans.push_back(mina);
    ans.push_back(smina);
    if(smina == 9998 || mina == 9999){
        return {-1};
        }
   else{
       return ans;
   }
}