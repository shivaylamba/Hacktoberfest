/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word
or phrase, typically using all the original letters exactly once. 
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

        //Time Complexity is O(nlog(n))
        //Space Complexity is O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i =0 ; i<s.size();i++){
            if(s[i]!=t[i]){
                return 0;
            }
        }
        return 1;
    }
};
         //Time Complexity is O(n)
        //Space Complexity is O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> check(26,0);
        for(int i = 0; i<s.size();i++){
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        for(auto i:check){
            if(i!=0) return false;
        }
        return true;;
    }
};
   // Most Optimized Solution 
   class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> mp(26,0);
        for(char c: s){
            mp[c-'a']++;
        }
        for(char c: t){
            if(mp[c-'a']==0) return false;
            mp[c-'a']--;
        }
        return true;
    }
};