/*
A and B are good friend and programmers. 
They are always in a healthy competition with each other. 
They decide to judge the best among them by competing. 
They do so by comparing their three skills as per their values. 
Please help them doing so as they are busy.
Set for A are like [a1, a2, a3]
Set for B are like [b1, b2, b3]
Compare ith skill of A with ith skill of B
if a[i] > b[i] , A's score increases by 1
if a[i] < b[i] , B's score increases by 1
if a[i] = b[i] , nothing happens
Example 1:
Input : 
A = {4, 2, 7}
B = {5, 6, 3}
Output : 
1 2
Example 2:
Input : 
A = {4, 2, 7}
B = {5, 2, 8}
Output : 
0 2
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function scores() which takes the array A[], 
B[] as inputs and two reference variables ca and cb to store the final answer. 
Store the score of A in ca and score of B in cb.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints :
1 ≤ a[i] ≤ 1017
1 ≤ b[i] ≤ 1017
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void scores(long long a[], long long b[], int &ca, int &cb)
    {
        // Your code goes here   
        ca = (a[0] > b[0]) + (a[1] > b[1]) + (a[2] > b[2]);
        cb = (a[0] < b[0]) + (a[1] < b[1]) + (a[2] < b[2]);
    }
};

//{ Driver Code Starts.
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        long long int a[5], b[5], i=0;
        int ca=0, cb=0;
        for(i=0; i<3; i++)
            cin>>a[i];
    
        for(i=0; i<3; i++)
            cin>>b[i];
        Solution ob;
        ob.scores(a, b, ca, cb);
        
        cout<<ca<<" "<<cb<<endl;
    }
    return 0 ;
}
// } Driver Code Ends