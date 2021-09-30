
//Author: Divyansh Sahu
//Implementation of gray code in c++ using bitset
#include <bits/stdc++.h>
int main(void)
{
    int n;
    n = 4;
    for (int i = 0; i < (1 << n); i++)
    {
        // Generating the decimal
        // values of gray code then using
        // bitset to convert them to binary form
        int val = (i ^ (i >> 1));

        std::bitset<32> r(val);
         
        // Converting to string
        std::string s = r.to_string();
        std::cout << s.substr(32 - n) << " ";
    }
}