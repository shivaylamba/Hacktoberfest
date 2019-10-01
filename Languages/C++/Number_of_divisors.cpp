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
                is_prime[i] = 1;
        }
    }

}

long long int num_of_div(long long int n){
    long long int ans = 1,idx = 0;
    long long int cur = primes[idx];
    while((n - 1) && cur * cur <= n){
        long long int power = 0;
        if(!(n%cur)){
            while(!(n%cur))
                n /= cur,power++;
            ans *= (power + 1);
        }
        idx++;
        cur = primes[idx];
    }
    if(n - 1)
        ans *= 2;
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
        cout << num_of_div(n) << "\n";
    }

 }
