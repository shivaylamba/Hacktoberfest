/*
1347. Minimum Number of Steps to Make Two Strings Anagram
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
 

Constraints:

1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.
*/
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>smp;
        unordered_map<char,int>tmp;
        int cnt=0;
        for(auto a:s)smp[a]++;
        for(auto a:t)tmp[a]++;

        for (auto a : smp) {
    if (tmp.find(a.first) != tmp.end()) {
        if (smp[a.first] == tmp[a.first]) {
            cnt += smp[a.first];
        } else {
            cnt += min(smp[a.first], tmp[a.first]);
        }
    }
}

        return s.size()-cnt;
    }
};

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::vector<int> count_s(26, 0);
        std::vector<int> count_t(26, 0);

        for (char ch : s) {
            count_s[ch - 'a']++;
        }

        for (char ch : t) {
            count_t[ch - 'a']++;
        }

        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += std::abs(count_s[i] - count_t[i]);
        }

        return steps / 2;  
    }
};