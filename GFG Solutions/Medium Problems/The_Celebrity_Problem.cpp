/*
The Celebrity Problem
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0],
                [0 0 0], 
                [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
Input: mat[][] = [[0 1],
                [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= mat.size()<= 3000
0 <= mat[i][j]<= 1
*/
// User function template for C++
/*
    MOST OPTIMIZDE APPROACH (STACK)
Time Complexity O(N)
Space Complexity O(N)
*/
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> s;
    // Celebrity
    int c;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (mat[a][b]) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }

    // Potential candidate?
    c = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != c)
            && (mat[c][i]
                || !mat[i][c] ))
            return -1;
    }

    return c;
    }
};
/*
    OPTIMIZDE APPROACH
Time Complexity O(N^N)
Space Complexity O(N)
*/
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int  n = mat.size();
         vector<int> indegree(n,0),outdegree(n,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = mat[i][j];
            outdegree[i] += x;
            indegree[j] += x;
        }
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;

    return -1;
    }
};