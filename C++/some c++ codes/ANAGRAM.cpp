#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    
    vector<int> count(26, 0);

    for(char c : s) 
        count[c - 'a']++;
    for(char c : t)
        count[c - 'a']--;

    for(int freq : count)
        if(freq != 0) 
            return false;

    return true;
}

int main() {
    string s1 = "anagram", t1 = "nagaram";
    cout << (isAnagram(s1, t1) ? "true" : "false") << endl;

    string s2 = "rat", t2 = "car";
    cout << (isAnagram(s2, t2) ? "true" : "false") << endl;

    return 0;
}
