/*
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
/*
   MOST OPTIMZED APPROACH
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> map;
        for(char ch:magazine){    map[ch]++;    }

        for(int i = 0 ;i<ransomNote.size();i++){
            if(map[ransomNote[i]]==0) return 0;
            map[ransomNote[i]]--;
        }
        return 1;
    }
};
/*
     OPTIMZED APPROACH
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> map1 , map2;
        for(char ch:ransomNote){    map1[ch]++;    }
        for(char ch:magazine){    map2[ch]++;    }

        for(int i = 0 ;i<ransomNote.size();i++){
            if(map1[ransomNote[i]] > map2[ransomNote[i]]) return 0;
        }
        return 1;
    }
};