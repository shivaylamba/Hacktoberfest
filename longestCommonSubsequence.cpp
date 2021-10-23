// https: //www.techiedelight.com/longest-common-subsequence/

// Longest Common Subsequence Problem


//without dp : complexity O(2^(m+n)) where m, n are length of two strings

// #include <iostream>
// #include <string>
// using namespace std;

// int LCSLength(string x, string y, int m, int n) {

//     if (m == 0 || n == 0)
//         return 0;
    
//     if (x[m-1] == y[n-1]) {
//         return LCSLength(x, y, m-1, n-1) + 1;
//     }

//     return max( LCSLength(x,y,m,n-1), LCSLength(x,y,m-1,n)) ;
// }

// int main(void) {
//     string x = "abcbdab", y = "bdcaaba";

//     cout << "The length of the LCS is " << LCSLength(x,y,x.length(), y.length());

//     return 0;
// }

//*************************************************************
// Using DP: 

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// int lcslength(string x, string y, int m, int n, auto &lookup) {
int lcslength(string x, string y, int m, int n, unordered_map<string,int> &lookup) {
    if (m == 0 || n == 0)
        return 0;
    
    string key = to_string(m) + "|" + to_string(n);

    if (lookup.find(key) == lookup.end()) {
        if (x[m-1] == y[n-1]) 
            lookup[key] = lcslength(x,y, m-1, n-1, lookup) +1;
        
        else
        {
            lookup[key] = max(lcslength(x,y, m, n-1, lookup), 
                            lcslength(x,y,m-1, n, lookup));

        }
        
    }

    //return the subproblem solution from the map
    return lookup[key];
}

int main(void) {
    string x = "abcbdab", y = "bdcaba";

    unordered_map<string, int> lookup;

    cout << "The length of the LCS is "
        << lcslength(x,y,x.length(), y.length(), lookup);

    return 0;
}