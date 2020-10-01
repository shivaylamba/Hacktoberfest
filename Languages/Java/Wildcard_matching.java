/* Wildcard Matching using Java

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.*/

class Solution {
    public boolean isMatch(String s, String p) {
        int i = 0, j = 0; //pointers pointing to characters of s and p
        int lastMatch = 0; //keeps track of last matched char after * in s
        int starIdx = -1;  //keeps track of position of start in p
        
        while (i < s.length()) {
            //if both chars match
            if (j < p.length() && (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i))) {
                i++;
                j++;
            }
            
            //if we encounter a star
            else if (j < p.length() && p.charAt(j) == '*') {
                starIdx = j++;
                lastMatch = i;
            }
            
            //if there a * before retrace back
            //handles the case if j reaches p.length or there is a mismatch of chars
            else if (starIdx != -1) {
                i = ++lastMatch;
                j = starIdx + 1;
            }
            
            else
                return false;
            
        }
        
        //check if the remaining chars in p are only stars
        while (j < p.length() && p.charAt(j) == '*') j++;
        
        return j == p.length();  //we don't need to check i because it won't exist the above loop if it doesn't reaches the end
    }
}
