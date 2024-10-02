/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements in the union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

Note : Elements are not necessarily distinct.

Your Task:
Complete doUnion funciton that takes a, n, b, m as parameters and returns the count of union elements of the two arrays. The printing is done by the driver code.

Constraints:
1 ≤ n, m ≤ 105
0 ≤ a[i], b[i] < 105
Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
*/
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template in C++
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        for(int j=0;j<m;j++){
            s.insert(b[j]);
        }
        return s.size();
    }
};
//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
        for(int i = 0;i<n;i++)
	       cout<< a[i]<<" ";
        cout<<endl;
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
        for(int i = 0;i<m;i++)
	       cout<< b[i]<<" ";
        cout<<endl;
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;    
	}
		return 0;
}