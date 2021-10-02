#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long

// function to compute longest prefix suffix array of given in put string
// input : pattern: string
// output : vector<long long>
// description : LPS array commonly used in KMP string pattern match algorithm
vector<ll> computeLPSArray(string pattern)
{
    ll prefixLen = 0, patLen = pattern.length();
    vector<ll> lpsArray(patLen, 0);
    ll i = 1;
    while (i < patLen)
    {
        if (pattern[prefixLen] == pattern[i])
        {
            lpsArray[i++] = ++prefixLen;
        }
        else
        {
            if (prefixLen != 0)
            {
                prefixLen = lpsArray[prefixLen - 1];
            }
            else
            {
                lpsArray[i++] = 0;
            }
        }
    }
    return lpsArray;
}

vector<ll> KMPsearch(string text, string pattern)
{
    vector<ll> lpsArray = computeLPSArray(pattern);
    vector<ll> matchIndexArray;
    ll textLen = text.length(), patLen = pattern.length(), i = 0, j = 0;
    while (i < textLen)
    {
        while (j < patLen && pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == patLen)
        {
            matchIndexArray.push_back(i - j);
            j = lpsArray[j - 1];
        }
        else
        {
            if (i < textLen && pattern[j] != text[i])
            {
                if (j > 0)
                {
                    j = lpsArray[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }
    return matchIndexArray;
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        cout << "./KMPsearch <text_string> <pattern_string>"
             << "\n";
    }
    else
    {
        string text(argv[1]), pattern(argv[2]);
        vector<ll> lpsArray = computeLPSArray(pattern);
        vector<ll> indexArray = KMPsearch(text, pattern);
        cout << "LPS array:\t";
        for (ll x : lpsArray)
        {
            cout << x << "\t";
        }
        cout << "\n";
        cout << "Match index array:\t";
        for (ll x : indexArray)
        {
            cout << x << "\t";
        }
        cout << "\n";
    }
    return 0;
}