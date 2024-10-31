from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

keyPair = RSA.generate(1024)
pubKey = keyPair.public_key()
print(f"Public Key: (n={hex(pubKey.n)},e={hex(pubKey.e)})")
pubKeyPEM = pubKey.exportKey()
print(pubKeyPEM.decode('ascii'))

print(f"Private Key: (n={hex(pubKey.n)},e={hex(keyPair.d)})")
privKeyPEM = keyPair.exportKey()
print(privKeyPEM.decode('ascii'))

msg = b"SIES Nerul"
msg =  msg.encode("utf-8")
encryptor = PKCS1_OAEP(pubKey)
encrypted = encryptor.encrypt(msg)
print("Encrypted: ",binascii.hexlify(encrypted))