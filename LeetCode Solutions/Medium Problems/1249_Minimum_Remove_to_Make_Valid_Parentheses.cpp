/*
1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Constraints:
1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
    int opc = 0 ;

        // First pass: mark excess closing parentheses with '*'
    for(int i = 0 ; i <s.size();i++){
        if(s[i]=='(') opc++;
        else if(s[i]==')'){  // marking excess Closed Parentheis
            if(opc==0){ s[i]='*';}
            else{
                opc--;
            }
        }
    }
            // Second pass: mark excess opening parentheses from the end
    // marking excess Closed Parentheis
    for(int i=s.size()-1;i>=0;i--){
        if(opc>0 && s[i]=='('){s[i]='*'; opc--;}
    }
        // Filter out marked characters and store the result in a new string
    string ans ="";
    for(char&ch:s){
        if(ch!='*'){ans+=ch;}
    }
    return ans;
    }
};