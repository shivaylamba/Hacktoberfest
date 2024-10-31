import math
def gcd(a,h):
    temp = 0
    while(1):
        temp = a%h
        if(temp==0):
            return h
        a=h
        h=temp
p=3
q=7
n=p*q
e=2
phi=(p-1)*(q-1)

while (e<phi):
    if(gcd(e,phi)==1):
        break
    else:
        e+=1

k=2
d = (1+(k*phi))/e
msg = 12.0
print("Message Data = ",msg)

c = pow(msg,e)
c = math.fmod(c,n)
print("Encrypted Data = ",c)

m = pow(c,d)
m = math.fmod(m,n)
print("Original Message sent = ",m)