from cryptography.fernet import Fernet

def generate_aes_key():
    return Fernet.generate_key()

# Generate a random AES key
aes_key = generate_aes_key()

# Create an AES cipher instance
cipher_suite = Fernet(aes_key)

# Data to encrypt
plaintext_data = b"This is some data to encrypt"

# Encrypt data
encrypted_data = cipher_suite.encrypt(plaintext_data)

# Decrypt data
decrypted_data = cipher_suite.decrypt(encrypted_data)

print("Original Data:", plaintext_data)
print("Encrypted Data:", encrypted_data)
print("Decrypted Data:", decrypted_data)
