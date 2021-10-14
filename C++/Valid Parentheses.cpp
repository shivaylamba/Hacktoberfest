/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
   Question link: https://leetcode.com/problems/valid-parentheses/
   Problem statement : Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  An input string is valid if:
  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Runtime: 0 ms O(n)
  Memory Usage: 6.2 MB
  Sample test case :
  Your input: []
  Output: true
  Expected: true  
  Approach :
  Receive input in the form of string.
  Traverse the string and when opening bracket found push it into an vector if closing bracket of same type of vector last element is 
  found then pop the vector element and if not return false. If vector is empty after traversing whole string return true else false.  
*/
class Solution {
public:
    bool isValid(string s) {
        vector <char> ch;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                ch.push_back(s[i]);
            }
            else{
                if(ch.empty())return false;
                int z=ch.size();
                if((s[i]==')'&&ch[z-1]=='(')||(s[i]==']'&&ch[z-1]=='[')||(s[i]=='}'&&ch[z-1]=='{')){
                    ch.pop_back();
                }
                else{
                    return false;
                }
            } 
        }
        if(ch.empty())
        return true;
        return false;
    }
};
