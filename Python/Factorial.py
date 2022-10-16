a=input("Enter a number")
a=int(a)
f=1
if(a<0):
  print("Factorial does not exist")
elif(a==0):
  print("Factorial of 0 is 1")
else:
    for i in range(1,a+1):
      f=f*i
    print("Factorial is ",f)
