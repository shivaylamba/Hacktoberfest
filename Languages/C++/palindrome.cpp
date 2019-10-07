#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    int t = 1, n;
    cout<<"Enter string: ";
    getline(cin, s);

    string::iterator it, it1;
    it1 = s.end() - 1;

    for(it = s.begin(); it != s.end(); it++) {      
        if(*it != *it1) {
            t = 0;
            break;
        }
        it1--;
    }

    if(t == 1)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;

    return 0;
}