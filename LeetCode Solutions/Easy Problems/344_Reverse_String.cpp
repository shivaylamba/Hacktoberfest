/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i =0 , j = s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
       void reverseString1(vector<char>& s) {
        char *p = &s[0], *q = &s[s.size() - 1];
        while (p < q) swap(*(p++), *(q--));
    }
};