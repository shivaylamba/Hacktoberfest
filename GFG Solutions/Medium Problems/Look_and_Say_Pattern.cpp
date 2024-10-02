/*
Look and Say Pattern
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.
Example 1:

Input:
n = 5
Output: 111221
Explanation: The 5th row of the given pattern
will be 111221.
Example 2:

Input:
n = 3
Output: 21
Explanation: The 3rd row of the given pattern
will be 21.

Your Task:  
You dont need to read input or print anything. Complete the function lookandsay() which takes integer n as input parameter and returns a string denoting the contents of the nth row of given pattern.


Expected Time Complexity: O(2n)
Expected Auxiliary Space: O(2n-1)  


Constraints:
1 ≤ n ≤ 30
*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
	// Base cases
	if (n == 1)	 return "1";
	if (n == 2)	 return "11";

	// Find n'th term by generating all terms from 3 to
	// n-1. Every term is generated using previous term
	string str = "11"; // Initialize previous term
	for (int i = 3; i<=n; i++)
	{
		// In below for loop, previous character
		// is processed in current iteration. That
		// is why a dummy character is added to make
		// sure that loop runs one extra iteration.
		str += '$';
		int len = str.length();

		int cnt = 1; // Initialize count of matching chars
		string tmp = ""; // Initialize i'th term in series

		// Process previous term to find the next term
		for (int j = 1; j < len; j++)
		{
			// If current character doesn't match
			if (str[j] != str[j-1])
			{
				// Append count of str[j-1] to temp
				tmp += cnt + '0';

				// Append str[j-1]
				tmp += str[j-1];

				// Reset count
				cnt = 1;
			}

			// If matches, then increment count of matching
			// characters
			else cnt++;
		}

		// Update str
		str = tmp;
	}

	return str;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends