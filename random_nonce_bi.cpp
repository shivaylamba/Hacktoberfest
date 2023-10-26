#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

pair<string, string> encryptXOR(const string &plaintext1, const string &plaintext2, const string &key)
{
    string ciphertext1 = plaintext1;
    for (size_t i = 0; i < plaintext1.size(); ++i)
    {
        ciphertext1[i] ^= key[i % key.size()];
    }
    string ciphertext2 = plaintext2;
    for (size_t i = 0; i < plaintext1.size(); ++i)
    {
        ciphertext2[i] ^= key[i % key.size()];
    }
    pair<string, string> p;
    p.first = ciphertext1;
    p.second = ciphertext2;
    return p;
}

pair<string, string> decryptXOR(const string &ciphertext1, const string &ciphertext2, const string &key)
{
    return encryptXOR(ciphertext1, ciphertext2, key);
}

string generateNonce()
{
    string nonce(16, '\0');
    for (int i = 0; i < 16; ++i)
    {
        nonce[i] = static_cast<char>(rand() % 256);
    }
    return nonce;
}

int main()
{
    string key, name;
    ifstream inFile("password.txt");
    if (!inFile.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return 1;
    }
    string line;
    if (getline(inFile, line))
    {
        key = line;
    }
    else
    {
        cout << "Key not found in the file." << endl;
        return 1;
    }
    cout << "Enter the claimant name: ";
    cin >> name;
    cout << endl
         << "The claimant sent its name to the verifier: " << name << endl;

    string serverNonce;
    cout << "The random generated nonce by verifier is: ";
    serverNonce = generateNonce();
    cout << serverNonce << endl;

    string clientNonce;
    cout << "The random generated nonce by claimant is: ";
    clientNonce = generateNonce();
    cout << clientNonce << endl;
    pair<string, string> p = encryptXOR(clientNonce, serverNonce, key);
    cout << "claimant:  encrypted nonce sent to verifier using symmetric key : " << p.first << p.second << endl;

    pair<string, string> q = decryptXOR(p.first, p.second, key);
    cout << "verifier : Received and decrypted nonce: " << q.first << q.second << endl;

    pair<string, string> p1 = encryptXOR(serverNonce, clientNonce, key);
    cout << "verifier:  encrypted nonce sent to claiment using symmetric key : " << p.first << p.second << endl;

    pair<string, string> q1 = decryptXOR(p1.first, p1.second, key);
    cout << "claiment : Received and decrypted nonce: " << q1.first << q1.second << endl;

    if (q1.first == serverNonce && q1.second == clientNonce)
    {
        cout << "Nonce verified , Access granted." << endl
             << endl;
    }
    else
    {
        cout << "Nonce verification failed , Access denied." << endl
             << endl;
    }
    return 0;
}
