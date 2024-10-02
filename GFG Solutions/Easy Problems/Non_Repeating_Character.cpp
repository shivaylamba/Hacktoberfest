/*
Non Repeating Character
Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 
Your Task:
You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= N <= 105
*/
/*
        HASH MAP
    Time Complexity O(n);
    Space Complexity O(n);
*/
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       map<char,int> map;
       for(char&ch:s){  map[ch]++;}
       for(char&ch:s){
           if(map[ch]==1){return ch;}
       }
       return '$';
       
    }

};
/*  Count array and single string traversal:
    Time Complexity: O(N), As the string needs to be traversed once
    Auxiliary Space: O(1), Space is occupied by the use of count-array to keep track of frequency.
*/
int firstNonRepeating(string str)
{
    int fi[256]; // array to store First Index
 
    // initializing all elements to -1
    for (int i = 0; i < 256; i++)
        fi[i] = -1;
 
    // sets all repeating characters to -2 and non-repeating
    // characters contain the index where they occur
    for (int i = 0; i < str.length(); i++) {
        if (fi[str[i]] == -1) {
            fi[str[i]] = i;
        }
        else {
            fi[str[i]] = -2;
        }
    }
 
    int res = INT_MAX;
 
    for (int i = 0; i < 256; i++) {
 
        // If this character is not -1 or -2 then it
        // means that this character occurred only once
        // so find the min index of all characters that
        // occur only once, that's our first index
        if (fi[i] >= 0)
            res = min(res, fi[i]);
    }
 
    // if res remains INT_MAX, it means there are no
    // characters that repeat only once or the string is
    // empty
    if (res == INT_MAX)
        return -1;
    else
        return res;
}