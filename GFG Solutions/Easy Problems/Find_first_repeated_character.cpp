/*
Find first repeated character
Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of second occurrence is smallest. S contains only lowercase letters.
Example 1:
Input: S="geeksforgeeks"
Output: e
Explanation: 'e' repeats at third position.
Example 2:
Input: S="hellogeeks"
Output: l
Explanation: 'l' repeats at fourth position.
Example 3:
Input: S="abc"
Output: -1
Explanation: There is no repeated character.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function firstRepChar() which accepts a string S as input parameter and returns a string containing first repeated character in it. If there is no repeated character in the string S then return "-1".
Expected Time Complexity: O(|S|) 
Expected Auxiliary Space: O(1)
where |S| denotes the length of string S.
*/
/*
    MOST OPTIMIZED APPROACH
        Time Complexity o(n)
        Space Complexity o(1)
*/
string firstRepChar(string s)
{
    // Create an array to store the count of characters
    int a[26] = { 0 };
 
    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
 
        // If the count of the character is not zero,
        // it means the character is repeated, so we return
        // it
        if (a[ch - 'a'] != 0)
            return string(1, ch);
        else
            // Increment the count of the character in the
            // array
            a[ch - 'a']++;
    }
 
    // If no character is repeated, return "-1"
    return "-1";
}
/*
    OPTIMIZED APPROACH
        Time Complexity o(n)
        Space Complexity o(n)
*/
string firstRepChar(string s)
{
    //code here.
    set<char> f;
    for(int i = 0 ; i <s.size();i++){
        if(f.find(s[i])!=f.end()){ s=s[i]; return s; }
        f.insert(s[i]);
    }
    return "-1";
}