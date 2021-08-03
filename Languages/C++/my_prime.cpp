#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
// Driver Program
int main()
{
    // take input
    int n;
    cin >> n;
    // check for prime number
    isPrime(n) ? cout << " true\n" : 
                  cout << " false\n";
    return 0;
}
