/*
Longest Common Prefix of Strings
Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103
*/

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here        
        int n = arr.size();
        if(n==0) return "-1";
        if(n==1) return arr[0];

        sort(arr.begin(),arr.end());
        int en = min(arr[0].size(),arr[n-1].size()) , i=0;
        string first = arr[0] , last = arr[n-1];
        while(i<en && first[i]==last[i]) i++;
        last =first.substr(0,i);
        return (last.size()==0)?"-1":last;
        
    }
};