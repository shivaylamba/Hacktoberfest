/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
*/
//   Most Optimized Approach
//    Time Complexity O(n);
//    Space Complexity O(n);
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";

        for(const string& s : word1)
            s1 += s;
        for(const string& s : word2)
            s2 += s;

        return s1==s2;
    }
};
//   Least Optimized Approach
//    Time Complexity O(n);
//    Space Complexity O(n);
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "",str2="";
        for(int i = 0 ; i<word1.size();i++){
            str1+=word1[i];
        }
         for(int i = 0 ; i<word2.size();i++){
            str2+=word2[i];
        }
        if(str1.size()!=str2.size()){
            return 0;
        }
        int i =0;
     while(i<str1.size() && i<str2.size()){
            if(str1[i]!=str2[i]){
                return 0;
            }
            i++;
     }
     return 1;
    }
};