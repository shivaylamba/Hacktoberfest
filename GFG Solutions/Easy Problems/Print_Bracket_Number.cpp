/*
Print Bracket Number
Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets, and '(', ')' characters
At any index, the number of opening brackets is greater than or equal to closing brackets
*/
/*
    MOST OPTIMZED APPROACH
Time Complexity : O(n). 
Auxiliary Space : O(n). 
*/
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        stack<int> st;
        vector<int> ans;
        int count = 1 ;
        for(int i = 0 ; i<str.size();i++){
           if(str[i]=='(') {
                st.push(count);
                ans.push_back(count);
                count++;
            }
            else{
                if(!st.empty()){
                if(str[i]==')'){ 
                    ans.push_back(st.top());
                    st.pop(); 
                    }
            }
            }
        }
        return ans;
        
    }
};