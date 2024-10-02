/*
Reverse words in a given string
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
Example 1:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:
Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr
Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 
Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stack<string> st;
        string s ="";
        for(char ch:str){
            if(ch!='.') s+=ch;
            else{
                st.push(s);
                s="";
            }
        }
        st.push(s);
        str="";
        while(!st.empty()){
            str+=st.top();
            if(st.size()!=1) str+='.';
            st.pop();
        }
        return str;
    }
};
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        string str = "";
        int i = 0 ;
        while(i<S.size()){
            if(S[i]=='.'){
                st.push(str);
                str="";
            }
            else{
                str+=S[i];
            }
            i++;
        }
        st.push(str);
        S="";
        while(!st.empty()){
            S+=st.top();
            S+=".";
            st.pop();
        }
        S.erase(S.size()-1,1);
        return S;
    } 
};