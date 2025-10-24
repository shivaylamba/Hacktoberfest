#include <iostream>
#include <string>
using namespace std;

// Multiply 2x2 matrix with 2x1 vector (mod 26)
void multiplyMatrix(int key[2][2], int vec[2], int result[2]) {
    result[0] = (key[0][0] * vec[0] + key[0][1] * vec[1]) % 26;
    result[1] = (key[1][0] * vec[0] + key[1][1] * vec[1]) % 26;
}

// Find modular inverse of determinant mod 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // No inverse
}

// Generate inverse of 2x2 matrix mod 26
int inverseMatrix(int key[2][2], int invKey[2][2]) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26;

    int detInv = modInverse(det, 26);
    if (detInv == -1) {
        cout << "Matrix not invertible. Decryption impossible.\n";
        return 1;
    }

    invKey[0][0] = (key[1][1] * detInv) % 26;
    invKey[0][1] = (-key[0][1] * detInv + 26) % 26;
    invKey[1][0] = (-key[1][0] * detInv + 26) % 26;
    invKey[1][1] = (key[0][0] * detInv) % 26;
}

// Convert character to index (A=0, B=1, ...)
int charToInt(char c) {
    return c - 'A';
}

// Convert index to uppercase character
char intToChar(int n) {
    return 'A' + n;
}

// Encrypt text with Hill cipher
string encrypt(string plaintext, int key[2][2]) {
    if (plaintext.length() % 2 != 0)
        plaintext += 'X'; // pad if odd length

    string ciphertext = "";
    int block[2], encBlock[2];

    for (int i = 0; i < plaintext.length(); i += 2) {
        block[0] = charToInt(plaintext[i]);
        block[1] = charToInt(plaintext[i + 1]);
        multiplyMatrix(key, block, encBlock);
        ciphertext += intToChar(encBlock[0]);
        ciphertext += intToChar(encBlock[1]);
    }

    return ciphertext;
}

// Decrypt text with Hill cipher
string decrypt(string ciphertext, int key[2][2]) {
    int invKey[2][2];
    inverseMatrix(key, invKey);

    string decrypted = "";
    int block[2], decBlock[2];

    for (int i = 0; i < ciphertext.length(); i += 2) {
        block[0] = charToInt(ciphertext[i]);
        block[1] = charToInt(ciphertext[i + 1]);
        multiplyMatrix(invKey, block, decBlock);
        decrypted += intToChar(decBlock[0]);
        decrypted += intToChar(decBlock[1]);
    }

    return decrypted;
}

int main() {
    string plaintext = "HELP";
    int key[2][2] = { {3, 3}, {2, 5} };  // Invertible 2x2 key matrix

    // Convert to uppercase
    for (int i = 0; i < plaintext.length(); i++)
        plaintext[i] = toupper(plaintext[i]);

    string encrypted = encrypt(plaintext, key);
    string decrypted = decrypt(encrypted, key);

    cout << "Plaintext : " << plaintext << endl;
    cout << "Encrypted : " << encrypted << endl;
    cout << "Decrypted : " << decrypted << endl;

    return 0;
}
