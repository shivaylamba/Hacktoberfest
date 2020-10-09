# -*- coding: utf-8 -*-

def isPrime(n):    
    if n == 2:
        prime = True
    else:
        if n == 1 or n % 2 == 0:
            prime = False
        else:
            prime = True
            nat = 3                
            while nat*nat <= n and prime:
                if n % nat == 0:    
                    prime = False
                nat = nat + 2
    return prime

def main():    
    c=2;
    b=3;
    a=5;
    n=int(input("Type a positive integer: "))
    if(n<10):
        print("%d is not the sum of three consecutive primes" % n);
    else:
        cont=6;
        print('');
        while(cont<n):
            if(isPrime(cont)):
                c=b;
                b=a;
                a=cont;
            if(a+b+c==n):
                print("%d is the sum of three consecutive primes." % n,"%d = %d + %d + %d" % (n,c,b,a),sep='\n');
                cont=n+1;
            cont=cont+1
        if(cont==n):
            print("%d is not the sum of three consecutive primes." % n)
main();