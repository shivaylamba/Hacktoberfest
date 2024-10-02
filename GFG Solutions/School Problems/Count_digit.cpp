/*
Given a number N. Count the number of digits in N which evenly divides N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.
Your Task:
You don't need to read input or print anything. Your task is to complete the function evenlyDivides() which takes an integer N as input parameters and returns an integer, total number factor of digits N which divides N evenly.

Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
 
Constraints:
1<=N<=105
*/
//{ Driver Code Starts
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;
// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int ans =0,count=0;
        int element = N;
        while(element>0){
            int ld = element%10;
           if(ld!=0){
                if(N%ld==0){
                ans++;
            }
           }
            element/=10;
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends