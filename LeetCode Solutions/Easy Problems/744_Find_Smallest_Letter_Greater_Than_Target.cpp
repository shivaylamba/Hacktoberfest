/*
744. Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
*/
// Most Optimized Approach
// Time Complexity O(log(n))
// space Complexity O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = -1;
        int s = 0, e = letters.size()-1;

        while (s<=e) {
            int m = (s+e)/2;

            if (letters[m] > target) {
                index = m;
                e = m-1;
            }
            else s = m+1;
        }

        return index>-1? letters[index]: letters[0];
    }
};
// Optimized Approach
// Time Complexity O(log(n))
// space Complexity O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0] ;
        int i=0 , j =letters.size()-1;
        int mid = i+(j-i)/2;
        while(i<=j){
            int x = letters[mid];
             if(x>target){
                ans = ;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
            mid = i+(j-i)/2;
        }
        return ans;
    }
};