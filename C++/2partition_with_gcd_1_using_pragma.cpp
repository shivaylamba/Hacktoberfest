/*
Here we are dividing an array into 2 partitions such that
p1=the product of all the numbers in the first group
p2=product of all the numbers in the second group
GCD(p1,p2)=1
using pragma
*/
#undef _GLIBCXX_DEBUG // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt") // bit manipulation

#pragma GCC target("aes,pclmul,rdrnd") // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#pragma GCC target("sse4,sse2")
#pragma GCC optimization("unroll-loops")
#pragma FUNC_ALWAYS_INLINE
#pragma CALLS(function_1_mangled_name, ..., function_n_mangled_name)
#pragma Optimize(identifier);
#pragma omp
#pragma onum
#pragma Otime
#pragma optimize("", on)
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long long int lll;

const ll mod = 1e9 + 7;

vector < int > values;

int setsize, mm;
vector < bool > primes, isprime;

vector < lll > ran, par;




 inline int find(int x) {
  if (par[x] == x)
    return (par[x]);

  #pragma omp parallel 
{
    #pragma omp single 
    {
      #pragma omp task shared(par[x])
      par[x] = find(par[x]);
    }
  }
  return (par[x]);
}

inline void merge(int xx, int yy) {

  #pragma omp parallel 
    {
    #pragma omp single 
        {
      #pragma omp task shared(xx) 
            {
        xx = find(xx);
      }
      #pragma omp task shared(yy)
       {
        yy = find(yy);
       }
     }
   } 

  if (xx != yy) {
    if (ran[xx] > ran[yy]) {
      par[yy] = xx;
      ran[xx] += ran[yy];
    } else {
      par[xx] = yy;
      ran[yy] += ran[xx];
    }
    setsize--;

  }
  return;

}

inline ll power(lll x, lll y) {
  ll res = 1;
  x = x % mod;

  if (x == 0) return 0;

  #pragma omp parallel 
  {
    while (y > 0) {
      if (y & 1)
        res = (res * x) % mod;
      y = y >> 1;
      x = (x * x) % mod;
    }
  }
  return res;
}


inline void SieveOfEratosthenes(int n) {
  int tmp = -1;

  #pragma omp parallel for collapse(2)
   
  {

    for (int p = 2; p <= n; p++) {

      tmp = -1;
      if (isprime[p]) {

        for (int i = p; i <= n; i += p) {
          isprime[i] = false;
          if (primes[i]) {
            if (tmp == -1) {
              tmp = i;
              continue;
            }
            merge(tmp, i);
          }
        }
      }

    }
  }
}


inline void countStablePartitions(int n, vector < int > & v, int & ma) {

  
  setsize = n;
  int one = 0;

  #pragma omp parallel for num_threads(ma+1)
  {

    for (int i = 0; i <= ma; i++) {
      par[i] = i;
      ran[i] = 1;
    }
  }

  #pragma omp parallel for num_threads(n)
   {
    for (int i = 0; i < n; i++) {
      primes[v[i]] = true;
      if (v[i] == 1)
        one++;

    }
  }

  setsize = n;

  SieveOfEratosthenes(ma + 1);

  if (setsize == 1) {
    cout << "NO" << endl << "0" << endl;
  } else {
    int sum = 0;
    ll ans;
    #pragma omp parallel
    {
      for (int i = 0; i < n; i++) {
        if (v[i] == 1)
          continue;
        if (primes[v[i]] == true) {
          //cout<<v[i]<<endl;
          if (find(v[i]) == v[i])
            sum++;
        }

        primes[v[i]] = false;
      }
    }

    sum += one;
   
    #pragma omp parallel
     {
      #pragma omp single
      ans = power(2, sum);
    }

    ans = ans % mod;
    ans = (ans - 2) % mod;
    ans = (ans + mod) % mod;
    cout << "YES" << endl << ans << endl;

  }

  return;

}



int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  //cin >> n;
  n=3;
  mm = n;

  values.resize(n);

  int ma = 1;
  #pragma omp parallel for num_threads(n)
   {

    for (int i = 0; i < n; i++)
     {
      //cin >> values[i];
        values[0]=2;
        values[1]=3;
        values[2]=1;


      ma = max(ma, values[i]);
    }
  }
  ran.resize(ma + 1);
  par.resize(ma + 1);
  primes.assign(ma + 1, false);
  isprime.assign(ma + 1, true);

  countStablePartitions(n, values, ma);
  return 0;
}
