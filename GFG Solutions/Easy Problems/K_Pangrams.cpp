/*
K-Pangrams
Given a string str and an integer K, find whether the string can be changed into a pangram after at most k operations. A pangram is a sentence containing every letter in the english alphabet. A single operation can be used to swap an existing alphabetic character with any other alphabetic character
Example 1:
Input:
str = "the quick brown fox jumps over the lazy dog"
k = 0
Output: 1
Explanation: the sentence contains all 26 characters 
and is already a pangram. 
Example 2:
Input:
str = "aaaaaaaaaaaaaaaaaaaaaaaaaa"
k = 25
Output: 1
Explanation: The word contains 26 instances of 'a'.
Since only 25 operations are allowed. We can keep
1 instance and change all others to make str a pangram.
Your Task:  
You dont need to read input or print anything. Complete the function kPangram() which takes str and k as input parameters and returns a boolean value which denotes if pangram is possible or not
Expected Time Complexity: O(N) where N is length of str.
Expected Auxiliary Space: O(1)  
Constraints:
1<= N <= 104
String may contain duplicate characters.
String can contain only lowercase alphabets or space.
*/
//---------------------------------short Method----------------------------------------//
/*
    HASHING
    Time Complexity o(n);
    Space Complexity o(26);
*/
bool kPangram(string str, int k)
{
    // code here 
    int n=0;
    vector<int> freq(26,0);
    for(int i = 0;i<str.size();i++){
       if(str[i]!=' '){ freq[str[i]-'a'] = 1;n++;}
    }
    if(n<26) return 0;
    int count =0;
    for(int i = 0 ; i<26;i++){
        if(!freq[i]){
            count++;
        }
    }
    return (count<=k);
}
//---------------------------------Long Method----------------------------------------//
bool kPangram(string str, int k)
{
    // code here 
        int n = str.size();
        for(int i=0;i<n;i++){
        if(str[i]==' '){
            str.erase(i,1);
            i--;
        }
    }
    n=str.size();
    if(n<26) return 0;
    vector<int> freq(26,0);
    for(int i = 0;i<n;i++){
       if(str[i]!=' '){ freq[str[i]-'a'] = 1;}
    }
    int count =0;
    for(int i = 0 ; i<26;i++){
        if(!freq[i]){
            count++;
        }
    }
    return (count<=k);
}