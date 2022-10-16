n=int(input("Enter number of terms:"))
a, b=0, 1
c=0
if n<=0:
 print("Enter positive number of terms")
elif n==1:
 print("Fibonacci series upto",n,":",a)
else:
 for i in range (c,n):
      print(a)
      sum=a+b
      a=b
      b=sum
      c=c+1
