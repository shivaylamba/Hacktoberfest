/*
917. Reverse Only Letters
Given a string s, reverse the string according to the following rules:
All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.
Example 1:
Input: s = "ab-cd"
Output: "dc-ba"
Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
Constraints:
1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/
// Most Optimized Approach - TWO POINTER APPROACH
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0 , j  = s.size()-1;
        while(i<j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i++],s[j--]);
            }
            else if( isalpha(s[i]) && !isalpha(s[j]) ){j--;}
            else{i++;}
        }
        return s;
    }
};