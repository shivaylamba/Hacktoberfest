# Import from pycryptodome
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
from Crypto.Protocol.KDF import PBKDF2
from base64 import b64encode

# BASIC AES
plain_text = b"Happy Hacktoberfest!"
key = get_random_bytes(32)  # 16 for AES-128, 24 for AES-192, 32 for AES-256 (key length/8).

cipher = AES.new(key, AES.MODE_CBC)  # Create encryption with our key, e.g. using CBC mode.
encrypt = cipher.encrypt(pad(plain_text, AES.block_size))  # We've got our cipher text!

# By recovering the iv of our previous cipher, we can now decrypt our text!
decipher = AES.new(key, AES.MODE_CBC, cipher.iv)
decrypted = unpad(decipher.decrypt(encrypt), AES.block_size)
print(f"BASIC AES:\n"
      f"    plain text : {plain_text},\n"
      f"    encrypted  : {b64encode(encrypt)},\n"
      f"    decrypted  : {decrypted}\n")

# PBKDF2 VERSION :
salt = b"Hacktoberfest"  # For the pbkdf2 version, we have to use a salt and a password.
password = "cyvax"  # for more security, those can be generated with get_random_bytes.

pbkdf2_key = PBKDF2(password, salt, dkLen=32)  # dkLen = 16 for AES-128, 24 for AES-192, 32 for AES-256 (key length/8).
pbkdf2_cipher = AES.new(pbkdf2_key, AES.MODE_CBC)
pbkdf2_encrypt = pbkdf2_cipher.encrypt(pad(plain_text, AES.block_size))

pbkdf2_decipher = AES.new(pbkdf2_key, AES.MODE_CBC, pbkdf2_cipher.iv)
pbkdf2_decrypted = unpad(pbkdf2_decipher.decrypt(pbkdf2_encrypt), AES.block_size)

print(f"AES with PBKDF2:\n"
      f"    plain text : {plain_text},\n"
      f"    encrypted  : {b64encode(pbkdf2_encrypt)},\n"
      f"    decrypted  : {pbkdf2_decrypted}")
