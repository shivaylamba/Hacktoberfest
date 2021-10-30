#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
    if(strlen(input)<=1)
        return;
    if(input[0]==input[1])
    {
        for(int i=1;input[i]!= '\0';i++)
        {
            input[i]=input[i+1];
        }
        return removeConsecutiveDuplicates(input);
    }
    return removeConsecutiveDuplicates(input+1);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
