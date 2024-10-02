/*
664. Strange Printer
There is a strange printer with the following two special properties:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.
Example 1:
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
Constraints:
1 <= s.length <= 100
s consists of lowercase English letters.
*/
class Solution {
public:
    int strangePrinter(const std::string& s) {
        if (s.empty()) return 0;
        
        // Remove consecutive duplicates
        std::vector<char> filtered_chars;
        for (char c : s) {
            if (filtered_chars.empty() || c != filtered_chars.back()) {
                filtered_chars.push_back(c);
            }
        }
        
        int m = filtered_chars.size();
        
        // Initialize DP table and last occurrence tracking
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, std::numeric_limits<int>::max()));
        std::vector<int> next_occurrence(m, -1);
        
        // Fill the DP table with base cases
        for (int i = 0; i < m; ++i) {
            dp[i][i] = 1;
        }
        
        // Precompute the next occurrence for each character
        std::unordered_map<char, int> last_seen;
        for (int i = m - 1; i >= 0; --i) {
            char c = filtered_chars[i];
            if (last_seen.find(c) != last_seen.end()) {
                next_occurrence[i] = last_seen[c];
            }
            last_seen[c] = i;
        }
        
        // Fill the DP table
        for (int length = 2; length <= m; ++length) {  // length of substring
            for (int start = 0; start <= m - length; ++start) {
                int end = start + length - 1;
                // Initial case: print each character separately
                dp[start][end] = dp[start + 1][end] + 1;
                // Try to find a better solution by matching characters
                char current_char = filtered_chars[start];
                int next_pos = next_occurrence[start];
                while (next_pos != -1 && next_pos <= end) {
                    dp[start][end] = std::min(dp[start][end], dp[start][next_pos - 1] + (next_pos + 1 <= end ? dp[next_pos + 1][end] : 0));
                    next_pos = next_occurrence[next_pos];
                }
            }
        }
        
        return dp[0][m - 1];
    }
};



