#Solution for CodeChef September 2020 Division 2 Long Challenge
#https://www.codechef.com/SEPT20B/problems/CRDGAME2
#author: kvv1618
# cook your dish here
mod=1000000007
def ncr(n, r, p): 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den, p - 2, p)) % p 
    return C[r] 
t=int(input())
for j in range(t):
    n=int(input())
    v=list(map(int, input().split()))
    m=max(v)
    d=0
    ans=0
    for i in range(n):
        if v[i]==m:
            d+=1
    if d%2!=0:
        ans=pow(2,n,mod)
    if d%2==0:
        ans=((pow(2,n,mod))-((ncr(d,d//2,mod))*(pow(2,n-d,mod))))%mod
    print(ans)
