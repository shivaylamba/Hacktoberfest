// number for given n.
#include <bits/stdc++.h>
using namespace std;
 
int setBitNumber(int n)
{
 
    // To find the position
    // of the most significant
    // set bit
    int k = (int)(log2(n));
 
    // To return the the value
    // of the number with set
    // bit at k-th position
    return 1 << k;
}
 
// Driver code
int main()
{
    int n = 273;
    cout << setBitNumber(n);
    return 0;
}