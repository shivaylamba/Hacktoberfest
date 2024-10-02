/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, 
more than once.
Example 1:
Input: s = "hello"
Output: "holle"
Example 2:
Input: s = "leetcode"
Output: "leotcede"
Constraints:
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/
class Solution {
public:
// Approach -1 
// Time Complexity O(n);
//  Space Complexity O(1);
bool isvowel(char c){
    return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ||
            c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    string reverseVowels(string s) {
        int i=0 , j = s.size()-1;
        while(i<j){
            if(isvowel(s[i]) && isvowel(s[j])){
                swap(s[i++],s[j--]);
            }
            else if(!isvowel(s[i])){
                i++;
            }
              else if(!isvowel(s[j])){
                j--;
            }
        }
        return s;
    }
// Approach -2 
// Time Complexity O(n);
//  Space Complexity O(n);
string reverseVowels(string s) {
      vector<int>v;
      for(int i=0;i<s.size();i++){
          if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
          v.push_back(i);
      }  
      for(int i=0;i<v.size()/2;i++){
          swap(s[v[i]],s[v[v.size()-1-i]]);
      }
      return s;
    }
};