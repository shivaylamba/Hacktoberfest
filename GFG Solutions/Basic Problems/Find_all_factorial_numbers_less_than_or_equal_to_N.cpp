/*
Find all factorial numbers less than or equal to N
A number N is called a factorial number if it is the factorial of a positive integer. 
For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number N, the task is to return the list/vector of the factorial numbers 
smaller than or equal to N.
Example 1:
Input: N = 3
Output: 1 2
Explanation: The first factorial number is 
1 which is less than equal to N. The second 
number is 2 which is less than equal to N,
but the third factorial number is 6 which 
is greater than N. So we print only 1 and 2.
Example 2:
Input: N = 6
Output: 1 2 6
Explanation: The first three factorial 
numbers are less than equal to N but 
the fourth factorial number 24 is 
greater than N. So we print only first 
three factorial numbers.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function 
factorialNumbers() which takes an integer N as an input parameter and return the 
list/vector of the factorial numbers smaller than or equal to N.
Expected Time Complexity: O(K), Where K is the number of factorial numbers.
Expected Auxiliary Space: O(1)
Constraints:
1<=N<=1018
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   // Time Complexity O(n)
   // Space Complexity O(1)
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans;
        long long int a = 1;
         long long int i=2;
        while(a<=N){
            ans.push_back(a);
            a*=i++;
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends