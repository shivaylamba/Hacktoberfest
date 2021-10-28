#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    string result = ""; 
    int s = 0;         
 
 
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
 
        result = char(s % 2 + '0') + result;
 
        s /= 2;
 
        i--; j--;
    }
    return result;
}
 
int main()
{
    string a = "1101", b="100";
    cout << addBinary(a, b) << endl;
    return 0;
}
