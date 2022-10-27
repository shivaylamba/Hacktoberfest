#include<iostream>
#include<unordered_set>
using namespace std;
char getFirstRepeatingChar(string &s) {
   unordered_set<char> hash;
   for (int i=0; i<s.length(); i++) {
      char c = s[i];
      if (hash.find(c) != hash.end())
         return c;
      else
         hash.insert(c);
   }
   return '\0';
}
int main () {
   string str = "Hello Friends";
   cout << "First repeating character is: " << getFirstRepeatingChar(str);
}
