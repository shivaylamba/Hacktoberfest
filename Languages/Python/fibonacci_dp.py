d={}
def fibo(n):
    if n==0:
        return 0

    if n==1:
        return 1

    if n in d:
        return d[n]
    else:
        ans=fibo(n-1)+fibo(n-2)
        d[n]=ans
        return ans    

print(fibo(int(input('Enter n for nth Fibonacci: '))))