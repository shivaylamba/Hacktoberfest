#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    int count = 1;

    // input
    cout<<"Enter string: ";
    getline(cin, str);

    // iterators for reading string
    string::iterator i, j;
    j = str.end() - 1;

    // reading and comparing from start and end
    for(i = str.begin(); i!= str.end(); i++) {      
        if(*i != *j) {
            count = 0;
            break;
        }
        j--;
    }

    // finally checking
    if(count == 1)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;

    return 0;
}