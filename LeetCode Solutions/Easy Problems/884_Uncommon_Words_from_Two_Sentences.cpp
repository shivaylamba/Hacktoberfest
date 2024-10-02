/*
884. Uncommon Words from Two Sentences
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Explanation:
The word "sweet" appears only in s1, while the word "sour" appears only in s2.
Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
Constraints:
1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
         map<string,int> map1,map2;
        string str = "";
        for(char ch:s1){
            if(ch!=' ') str+=ch;
            else{ 
             map1[str]++;
             str="";
             }    
        }
        map1[str]++;
        str="";

         for(char ch:s2){
            if(ch!=' ') str+=ch;
            else{ 
            map2[str]++;
             str="";
             }    
        }
        map2[str]++;
        str="";

    for(auto i:map2){
        string sen = i.first;
        int n1 = i.second;
        if(map1[sen]) map1[sen] += n1;
        else map1[sen]= n1;
    }
    for(auto i:map1) if(i.second==1) ans.push_back(i.first);
    // for(auto i:map1)ans.push_back(i.first);
    return ans;
    }
};