a={}
def fib(n):
    if n==0:
        return 0

    if n==1:
        return 1

    if n in a:
        return a[n]
    else:
        ans=fib(n-1)+fib(n-2)
        d[n]=ans
        return ans    

print(fib(int(input('Enter n : '))))