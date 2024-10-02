/*
Given two integers A and B. Your task is to return their product.
Example 1:
Input:
A = 1, B = 2
Output:
2
Explanation:
Multiplication of 1 and 2 is 2.
Example 2:
Input:
A = 8, B = 7
Output:
56
Explanation:
Multiplication of 8 and 7 is 56.
Your Task:
You don't need to read input or print anything. Your task is to 
complete the function multiplication() which takes two integers 
a and b and returns their product.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints:
0<=a,b<=10000
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int multiplication(int A, int B){
        // code here 
        return A*B;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.multiplication(A,B) << endl;
    }
    return 0; 
} 

// } Driver Code Ends