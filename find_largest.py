a=int(input("first number"))
b=int(input("second number"))
c=int(input("third number"))
if(a>=b and a>=c):
    d=a
elif(b>=a and b>=c):
    d=b
elif(c>=a and c>=b):
    d=c
print("greatest number is : ")
print(d)
