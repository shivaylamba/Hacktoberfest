import math
def check_prime(n):
    if n%2==0:
        return False
    for i in range(3,int(math.sqrt(n))+1,2):
        if n%i==0:
            return False
    return True
#Check number 11247 is prime?
if check_prime(11247):
    print("It's a prime!!.")
