/*
Subsets
Given a set of positive integers, find all its subsets.

Example 1 :

Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3
Explanation: 
The following are the subsets 
of the array {1, 2, 3}.
Example 2 :

Input :
array = {1, 2}
Output :

1 
1 2
2
Explanation :
The following are the 
subsets of {1, 2}.
Your task :
You don't have to read input or print anything. Your task is to complete the function subsets() which takes the array of integers as input and returns the list of lists containing the subsets of the given set of numbers in lexicographical order.
 
Expected Time Complexity : O(2n)
Expected Auxiliary Space : O((2n)*length of each subset)
 
Constraints :
1 <= n <= 15
1 <= arr[i] <=104
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void solve(vector<int> arr , vector<int>output,int index,vector<vector<int>>&ans){
        if(index>=arr.size()){
            ans.push_back(output);
            return;
        }
        solve(arr,output,index+1,ans);
        output.push_back(arr[index]);
        solve(arr,output,index+1,ans);
    }
  public:
    vector<vector<int> > subsets(vector<int>& a) {
        // code here
                //code here
        vector<vector<int>>ans;
        vector<int> output;
        int index = 0 ;
        solve(a,output,index,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends