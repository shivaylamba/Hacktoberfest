#include <bits/stdc++.h> 
using namespace std; 
  
string MaxString(string str) 
{ 
    // loop to find the max leicographic 
    // substring in the substring array 
    string mx = ""; 
    for (int i = 0; i < str.length(); ++i) 
        mx = max(mx, str.substr(i)); 
  
    return mx; 
} 
  
int main() 
{ 
    string str = "ababaa"; 
    cout << MaxString(str); 
    return 0; 
} 