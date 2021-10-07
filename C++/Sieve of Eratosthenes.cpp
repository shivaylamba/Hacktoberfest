#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<int> prime(N,1);
// A Fuction to pre-compute all the prime numbers present in a given range in n(log(log(n))) time complexity and to check whether a number is prime or not, and give the output in constant time complexity for any number of queries.
void Sieve()
{
    prime[0]=prime[1]=0;
    for(int i=2;i<N;i++)
    {
        if(prime[i]==1)
        {
        for(int j=2*i;j<N;j+=i)
        {
            prime[j]=0;
        }
        }
    }

}
int main()
{
    Sieve();
    for(int i=0;i<=100;i++)
    {
        if(prime[i])
        cout<<i<<" "<<"is a prime number"<<endl;
        else
        cout<<i<<" "<<"is not a prime number"<<endl;
    }
}