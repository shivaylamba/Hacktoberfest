
#Program to find geometeric sum , with input k
#The given form is geometric series and we will find sum of this series
#1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 



def find(k):
  if(k==0):
    return 1
  a=1/2**k
  return (a+find(k-1))
k=int(input())
print("{:.5f}".format(find(k)))