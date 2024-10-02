/*
557. Reverse Words in a String III
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:
Input: s = "Mr Ding"
Output: "rM gniD"
Constraints:
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
/*
    TWO POINTER APPROACH
Time Complexity o(n);
Space Complexity o(1);
*/
class Solution {
public:
    string reverseWords(string s) {
        int i = 0 , j = 0 ;
        while(j<s.size()){
            if(s[j]==' '){
                reverse(s.begin()+i , s.begin()+j);
                i=j+1;
            }
            j++;
        }
        reverse(s.begin()+i , s.begin()+j);
        return s;
    }
};