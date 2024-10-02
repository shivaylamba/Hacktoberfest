/*
409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.
Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
class Solution {
public:
    int longestPalindrome(const std::string& s) {
        // Initialize a set to keep track of characters with odd frequencies
        std::unordered_set<char> charSet;
        // Initialize the length of the longest palindrome
        int length = 0;
        
        // Iterate over each character in the string
        for (char c : s) {
            // If the character is already in the set, remove it and increase the length by 2
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                // If the character is not in the set, add it to the set
                charSet.insert(c);
            }
        }
        
        // If there are any characters left in the set, add 1 to the length for the middle character
        if (!charSet.empty()) {
            length += 1;
        }
        
        // Return the total length of the longest palindrome
        return length;
    }
};
