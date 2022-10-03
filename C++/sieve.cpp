#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    bool isNotPrime[n+1];
    memset(isNotPrime,false,sizeof(isNotPrime));
    
    isNotPrime[0]=true;
    isNotPrime[1]=true;
    
    for(int i=2;i*i<=n;i++)
    {
        if(isNotPrime[i]==false)
            for(int j=i*i;j<=n;j=j+i)
                isNotPrime[j]=true;
    }
    
    for(int i=0;i<=n;i++)
    {
        if(isNotPrime[i]==false)
            cout << i << endl;
    }
}
/* C++ code to find the primes in the range [1,n] using the algorthim 
   sieve of eratosthenes in O(nloglogn) time complexity
   The array isNotPrime stores if the i'th number is a prime number or not
*/
