/*
Anagram
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.
Note:-
If the strings are anagrams you have to return True or else return False
|s| represents the length of string s
Example 1:
Input:a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same characters with
        same frequency. So, both are anagrams.
Example 2:
Input:a = allergy, b = allergic
Output: NO
Explanation: Characters in both the strings are 
        not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.
Expected Time Complexity:O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).
Constraints:
1 ≤ |a|,|b| ≤ 105
*/
//{ Driver Code Starts
/*
    Hashmap
Time Complexity O(n)
Space Complexity O(26)
*/
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<int,int> map;
        for(char i:a) map[i]++;
        for(char i:b){
            if(map[i]){
                map[i]--;
                if(map[i]==0) map.erase(i);
            }
        }
        return (map.size()==0)?1:0;
        
    }

};
/*
    Hashmap
Time Complexity O(n)
Space Complexity O(26)
*/
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
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
/*
    Hashmap
Time Complexity O(n)
Space Complexity O(26)
*/
class Solution
{
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
/*
    By Using Two Hashmap
Time Complexity O(n)
Time Complexity O(52)
*/
class Solution
{
    public:   
    bool isAnagram(string a, string b){
        // Your code here
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(char &ch:a){a1[ch-'a']++;}
        for(char &ch:b){a2[ch-'a']++;}
        for(int i=0;i<26;i++){
            if(a1[i]!=a2[i]){
                return 0;
            }
        }
        return 1;   
    }  
};
/*
    By Sorting
Time Complexity O(n*log(n))
Space Complexity O(n)
*/
class Solution
{
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