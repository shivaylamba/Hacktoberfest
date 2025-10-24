#include <iostream>
#include <string>
using namespace std;

// finding modular inverse (used in decryption)
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // No inverse exists
}


char encryptChar(char ch, int a, int b) {
    if (ch >= 'A' && ch <= 'Z') {
        return ((a * (ch - 'A') + b) % 26) + 'A';
    }
    return ch; // Ignore non-uppercase
}


char decryptChar(char ch, int a_inv, int b) {
    if (ch >= 'A' && ch <= 'Z') {
        return ((a_inv * (ch - 'A' - b + 26)) % 26) + 'A';
    }
    return ch;
}

// Encrypt full string
string encrypt(string plaintext, int a, int b) {
    string result = "";
    for (char ch : plaintext) {
        result += encryptChar(ch, a, b);
    }
    return result;
}

// Decrypt full string
string decrypt(string ciphertext, int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        return "Invalid key: no modular inverse!";
    }
    string result = "";
    for (char ch : ciphertext) {
        result += decryptChar(ch, a_inv, b);
    }
    return result;
}

int main() {
    string plaintext = "HELLOWORLD";
    int a = 5; // a must be coprime with 26 (valid: 1, 3, 5, 7, 11, 15, 17, 19, 21, 23, 25)
    int b = 8;

    string encrypted = encrypt(plaintext, a, b);
    string decrypted = decrypt(encrypted, a, b);

    cout << "Plaintext:  " << plaintext << endl;
    cout << "Encrypted:  " << encrypted << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}
