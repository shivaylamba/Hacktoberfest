#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
 
bool isPalindrome(string str)
{
   
    int count[NO_OF_CHARS] = { 0 };
 
    for (int i = 0; str[i]; i++)
        count[str[i]]++;
 
    int odd = 0;
    for (int i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] & 1)
            odd++;
 
        if (odd > 1)
            return false;
    }
 

    return true;
}
 

int main()
{
    string word;
    cout<<"Enter a string :";
    cin>>word;
    isPalindrome(word)
      ? cout << "YES, the string CAN be rearranged to form a pallindrome\n"
      : cout << "NO, the string CANNOT be rearranged to form a pallindrome\n";
   
    return 0;
}
