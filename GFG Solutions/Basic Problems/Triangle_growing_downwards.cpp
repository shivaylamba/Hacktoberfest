/*
Triangle growing downwards
Given string str of a constant length, print a triangle out of it. The triangle should start with the first character of the string and keep growing downwards by adding one character from the string.
The spaces on the left side of the triangle should be replaced with a dot character. 

Example 1:

Input:
str = "geeks"

Output:
....g
...ge
..gee
.geek
geeks
Example 2:

Input:
str = "thisi"

Output:
....t
...th
..thi
.this
thisi
Your Task:  
You don't need to read input. Your task is to complete the function printTriangleDownwards() which takes the string str as an input parameter and prints the required triangle.

Expected Time Complexity: O(N*N), Where N is the size of input string.
Expected Auxiliary Space: O(1)

Constraints:
1 <= |str| <= 500
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void printTriangleDownwards(string str)
    {
        // Write Your Code here
        for(int i=1;i<=str.size();i++){
            for(int j=str.size()-i;j>=1;j--){
                cout<<".";
            }
            for(int j=0;j<i;j++){
                cout<<str[j];
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        ob.printTriangleDownwards(str);
    }
    return 0;
}
// } Driver Code Ends