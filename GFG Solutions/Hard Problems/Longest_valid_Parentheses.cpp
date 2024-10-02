/*
Longest valid Parentheses
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.
A parenthesis string is valid if:
For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :
Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)
Constraints:
1 ≤ |str| ≤ 105  
*/
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
         int n = str.size();
        stack<int> st;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(str[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() && str[st.top()] == '(')
                {
                    st.pop();
                    int first = st.empty() ? -1 : st.top();
                    ans = max(ans,i-first);
                }
                else 
                {
                    st.push(i);
                }
            }
        }
        return ans;
    }
};