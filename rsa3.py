import random
import math

prime = set()
public_key = None
private_key = None
n = None

def primefiller():
    seive = [True]*250
    seive[0]=False
    seive[1]=False
    for i in range(2,250):
        for j in range(i*2,250,i):
            seive[j]=False

    for i in range(len(seive)):
        if seive[i]:
            prime.add(i)

def pickrandomprime():
    global prime
    k = random.randint(0,len(prime)-1)
    it=iter(prime)
    for _ in range(k):
        next(it)

    ret = next(it)
    prime.remove(ret)
    return ret

def setkeys():
    global public_key,private_key,n
    prime1 = pickrandomprime()
    prime2 = pickrandomprime()
    n = prime1*prime2
    fi = (prime1-1)*(prime2-1)
    e=2
    while True:
        if math.gcd(e,fi)==1:
            break
        e+=1
    public_key=e
    d=2
    while True:
        if (d*e)%fi==1:
            break
        d+=1
    private_key=d

def encrypt(message):
    global public_key,n
    e = public_key
    encrypted_text=1
    while e>0:
        encrypted_text *= message
        encrypted_text %=n
        e-=1
    return encrypted_text

def decrypt(encrypted_text):
    global private_key,n
    d = private_key
    decrypted=1
    while d>0:
        decrypted *= encrypted_text
        decrypted %=n
        d-=1
    return decrypted

def encoder(message):
    encoded = []
    for letter in message:
        encoded.append(encrypt(ord(letter)))
    return encoded

def decoder(encoded):
    s=''
    for num in encoded:
        s+=chr(decrypt(num))
    return s

if __name__=="__main__":
    primefiller()
    setkeys()
    message = "Shubham"
    coded = encoder(message)
    print("Initial Message")
    print(message)
    print("The encoded message encrypted by public key:")
    print(''.join(str(p) for p in coded))
    print("The decoded message decrypted by public key:")
    print(''.join(str(p) for p in decoder(coded)))