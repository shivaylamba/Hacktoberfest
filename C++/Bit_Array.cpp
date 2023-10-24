#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    uint_fast64_t po = (uint_fast64_t)(pow(2, 31));
    uint_fast64_t N, S, P, Q;
    cin >> N >> S >> P >> Q;

    bool r = false;
    uint_fast64_t c = 0;
    uint_fast64_t prv = S % po;
    uint_fast64_t crn = -1;
    uint_fast64_t i = 1;

    do 
    {
        crn = (prv * P + Q) % po;
        if (crn != prv) 
        {
            prv = crn;
            ++c;
        } 
        else 
        {
            r = true;
        }
        ++i;
    } while (i < N && !r);
    cout << c + 1 << endl;

    return 0;
}