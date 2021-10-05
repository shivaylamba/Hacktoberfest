
int Solution::solve(int n) {
   if(n==0)
        return 0;
    long long ans = 0;
    long long p = 0;
    while(pow(2,p)<=n) p++;
    p--;
    ans+=p*pow(2,p)/2+(n - pow(2,p)+1)+solve(n - pow(2,p));
    // first term is for the numbers form 1 to 7
    // 2nd term is for the set bit on the 8th position
    // last one is for the recursice function for the upcoming funciton calls and the 
    // remaining numbers
    ans= ans %(1000000000 + 7);
    return ans;
}
