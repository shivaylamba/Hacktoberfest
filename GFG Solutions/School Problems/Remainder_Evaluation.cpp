/*
Given two positive integers num1 and num2, the task is to find the remainder when num1 is divided by num2.

Example 1:

Input:
num1 = 5
num2 = 3

Output:
2

Explanation:
The remainder after dividing 5 by 3 is: 2.
Example 2:

Input:
num1 = 5
num2 = 10

Output:
5

Explanation:
5 cannot be divided by 10 so it is 
the Remainder.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findRemainder() which takes two integer num1 and num2 as an input parameter and return the remainder when num1 is divided by num2.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
0 <= num1 <= 106
1 <= num2 <= 106
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int findRemainder(int num1,int num2)
    {
        // Write Your Code here
        return num1%num2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num1,num2;
        cin>>num1>>num2;
        Solution ob;
        int ans  = ob.findRemainder(num1,num2);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends