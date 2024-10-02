/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
*/
// Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowelsCount = 0;
        int midIndex = s.length() / 2;

        for (int i = 0; i < midIndex; i++) {
            char charA = s[i];
            char charB = s[midIndex + i];
            if (vowels.count(charA)) vowelsCount++;
            if (vowels.count(charB)) vowelsCount--;
        }

        return vowelsCount == 0;
    }
};

// Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
public:
bool isVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
    ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' );
}
    bool halvesAreAlike(string s) {
        int n =s.size();
        int mid = n/2;
        int av=0,bv=0;
        int i=0 , j = mid;
    while(i<mid){
        if(isVowel(s[i])){
            av++;
        }
        i++;
    }
    while(j<n){
        if(isVowel(s[j])){
            bv++;
        }
        j++;
    }
    return (av==bv);
    }
};