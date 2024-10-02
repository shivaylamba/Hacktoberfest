/*
Print a sequence of numbers starting with N, without using loop, where replace 
N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.
Example 1:
Input: 
N = 16
Output: 
16 11 6 1 -4 1 6 11 16
Explaination: 
The value decreases until it is greater than 0. After that it increases and stops 
when it becomes 16 again.
Example 2:
Input: 
N = 10
Output: 
10 5 0 5 10
Explaination: It follows the same logic as per the above example.
Your Task:
You do not need to read input or print anything. Your task is to complete the function 
pattern() which takes N as input parameters and returns a list containing the pattern.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
-105 ≤ N ≤ 105
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        int n = N;
        while(n>0){
            ans.push_back(n);
            n-=5;
        }
        while(n<=N){
            ans.push_back(n);
            n+=5;
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends