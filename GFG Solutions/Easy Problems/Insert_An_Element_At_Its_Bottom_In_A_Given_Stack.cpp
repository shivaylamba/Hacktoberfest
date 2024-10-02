/*
You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.

 

Example 1:

Input:
N = 5
X = 2
St = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
 

Example 2:

Input:
N = 3
X = 4
St = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function insertAtBottom() which takes a stack St and an integer X  as inputs and returns the modified stack after insertion.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 105
1 <= X, Elements of Stack <= 103
Sum of N over all test cases doesn't exceeds 106
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(stack<int>& st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int n =st.top();
    st.pop();
    solve(st,x);
    st.push(n);
}
    stack<int> insertAtBottom(stack<int> St,int X){
        solve(St,X);
        return St;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends