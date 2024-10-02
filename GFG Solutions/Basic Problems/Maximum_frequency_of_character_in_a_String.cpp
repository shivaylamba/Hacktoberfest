/*
Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str. If more than one character occurs the
maximum number of time then print the lexicographically smaller character.
Example 1:
Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
Your Task:
The task is to complete the function getMaxOccuringChar() which returns the character which is most occurring.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |s|

Constraints:
1 ≤ |s| ≤ 100


*/
#include<bits/stdc++.h>
using namespace  std;
int main(){
    string str ;
    getline(cin,str);
  int frequency[26];
  for(int i=0;i<26;i++){
    frequency[i]=0;
  }
  for(int i=0;i<str.size();i++){
    frequency[str[i]-'a']++;
  }
  char ans = 'a';
  int max = 0;
  for(int i=0;i<26;i++){
    if (frequency[i] > max){
        max = frequency[i];
        ans = i+'a';
    }
  }
  cout<<"the character : "<<ans<<" with the Maximum frequency is : "<<max<<endl;
  return 0;
}