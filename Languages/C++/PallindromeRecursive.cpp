#include <string.h>
#include <iostream>
using namespace std;

bool checkpalindromehelper(char input[], int startindex, int endindex)
{
    if (startindex >= endindex)
        return true;
    if (input[startindex] == input[endindex])
    {
        bool ans = checkpalindromehelper(input, startindex + 1, endindex - 1);
        return ans;
    }
    else
        return false;
}

bool checkPalindrome(char input[])
{
    bool result = checkpalindromehelper(input, 0, strlen(input) - 1);
    return result;
}

int main()
{
    char input[50];
    cout << "Enter string (in caps) : ";
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}