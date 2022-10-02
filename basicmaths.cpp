#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>

using namespace std;
    
//no.of digits in n
//floor(log10(n)+1)=ceil(log10(n))


//no.of bits in binary form in n
//floor(log2(n)+1)=ceil(log2(n))


//use (a%b + b)%b over a%b to avoid negativr remainders


//to find digits int the factorial of a number
int digitsInFactorial(int N)
    {
        double ans=0;
        for(int i=2;i<=N;++i)
        {
            ans = ans + log10(i);
        }
        return ceil(ans);
    }



//no.of factors of a number
int numoffac(int m){
int count=0;
for(int i=1;i<=sqrt(m);++i)
{
    if(m%i==0)
    {
        if(m/i==i)
        {
            count++;
        }
        else
        {
            count=count+2;
        }
    }
}
//sum of factors is similar
return count;
}





//gcd
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// lcm(a,b)*gcd(a,b)=a*b
//or simply use __gcd(a,b)  STL function 



/*Modular Inverse
if M%(a*x)=1 then x is modular inverse and x<M and x>=0*/
int minv(int m,int a)
{
    for (int i = 0; i < m; i++)
    {
        if(m%(a*i)==1)  return i;
    }
}


/*Mod rules
(a+b)%m= (a%m +b%m)%m
(a*b)%m= (a%m *b%m)%m*/




//Fermat's Little Theorem         if m is prime then  (a^m -a)%m=0  for all a


// sum of all proper divisiors of n= (sum of reciprocal of all proper divisors)*n



/*if we have 2 numbers a and b
let z= a + (b*n)   now   z%n=a and z/n=b    #a should be greater than n
*/




//Sieve of Ertosthenes
// no.of prime numbers less than a number


vector<int> chechprime(int n){
    vector<bool> prime(n+1,true);  // all values are true
    for(int p=2;p*p<=n;++p){
        if(prime[p]==true)
        {
            for(int i= p*p; i<=n;i=i+p)
            {
                prime[i]=false;    //if 2 is prime then 4,6,8,10 can't be prime
            }
        }
    }
}





//binary exponentiation to calculate a^n in O(logn)  using bits
/*
13= 1101 in binary
3^13 = 3^8 * 3^4 * 3^1
it follows
       1   if n=0
a^n=   a^(n/2) * a^(n/2)    if n%2==0
       a^((n-1)/2) * a^((n-1)/2) * a    if n%2==1
*/

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  //if b is odd
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}




// (a^b)%m using binary when b is very large
long long binpowr(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}




//excel column number from title
/*
To convert CDA,
3*26*26 + 4*26 + 1
loop through string and result = 26*result + s[i] - 'A' + 1
*/