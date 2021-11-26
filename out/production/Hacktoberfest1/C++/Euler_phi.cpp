#include <bits/stdc++.h>
#define maxN 1000007
using namespace std;

bool is_prime[maxN];
vector<int> primes;

void seive(){
    primes.push_back(2);
    for(int i = 3;i < maxN; i+=2){
        if(!is_prime[i]){
            primes.push_back(i);
            for(int j = i*2;j < maxN;j+=i)
                is_prime[j] = 1;
        }
    }

}

long long int euler_phi(long long int n){
    long long int ans = n,idx = 0;
    long long int cur = primes[idx];
    while((n - 1) && cur * cur <= n){
        if(!(n%cur)){
            ans -= ans/cur;
            while(!(n%cur))
                n /= cur;
        }
        idx++;
        cur = primes[idx];
    }
    if(n - 1)
        ans -= 1;
    return ans;
}

int main()
 {
    seive();
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << euler_phi(n) << "\n";
    }

 }
