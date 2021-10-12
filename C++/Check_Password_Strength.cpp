// A C++ Program to determine input password security
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string password;
    bool istrue = 1;
    cout << "The Password Must Satisfy the following criteria" << endl;
    cout << "\nAt least 1 letter between [a-z]" << endl;
    cout << "At least 1 number between [0-9]" << endl;
    cout << "At least 1 letter between [A-Z]" << endl;
    cout << "At least 1 character from [$#@]" << endl;
    cout << "Minimum length of transaction password: 6" << endl;
    cout << "Maximum length of transaction password: 12" << endl;
    cout << "\nPlease input your password" << endl;
    getline(cin, password);
    istrue = any_of(password.begin(), password.end(), ::isdigit);
    if(istrue == 0)
    {
        cout << "The entered password must have a digit" << endl;
    }
    istrue = any_of(password.begin(), password.end(), ::islower);
    if(istrue == 0)
    {
        cout << "The entered password must have a lowercase letter" << endl;
    }
    istrue = any_of(password.begin(), password.end(), ::isupper);
    if(istrue == 0)
    {
        cout << "The entered password must have an uppercase letter" << endl;
    }
    for(auto index : password)
    {
        if(index == '#'||index == '@'||index == '$')
        {
            istrue = 1;
            break;
        }
        else 
        {
            istrue = 0;
        }
    }
    if(istrue == 0)
    {
        cout << "The entered password must have a character in [$#@]" << endl;
    }
    if(password.size()<6||password.size()>12)
    {
        cout << "The entered password must be 6-12 characters long" << endl;
        istrue=0;
    }
    if(istrue == 1)
    {
        cout << "The entered password is strong, congratulations" << endl;
    }
    return 0;
}
