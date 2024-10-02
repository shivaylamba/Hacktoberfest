/*
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' 
appears before every 'b' in the string. Otherwise, return false.
 
Example 1:
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
Example 2:
Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
Example 3:
Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
Constraints:
1 <= s.length <= 100
s[i] is either 'a' or 'b'.
*/
class Solution {
public:
    bool checkString(string s) {
        //  Approach 1st time Complexity O(nlog(n))
        // Space Complexity is O(n)
        // string str =s;
        // sort(s.begin(),s.end());
        // return (str==s);

        // Approach 2nd time Complexity O(n)
        // Space Complexity is O(1)
       for(int i=0;i<s.size()-1;i++){
           if(s[i]=='b' && s[i+1] == 'a'){
               return 0;
           }
       }
       return 1;
    }
};