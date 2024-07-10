#include <iostream>
#include <cstring>
using namespace std;
string encrypt(const string& message, int shift) {  // Function to encrypt
    string encryptedMessage = "";
    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encryptedMessage += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            encryptedMessage += ch;
        }
    }
    return encryptedMessage;
}
string decrypt(const string& message, int shift) {   // Function to decrypt
    return encrypt(message, 26 - shift);  // Again encrypting and returning original message
}
int main() {
    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);
    int shift;
    cout << "Enter the shift value: ";
    cin >> shift;
    string encryptedMessage = encrypt(message, shift);
    cout << "Encrypted Message: " << encryptedMessage << endl;
    string decryptedMessage = decrypt(encryptedMessage, shift);
    cout << "Decrypted Message: " << decryptedMessage << endl;
    return 0;
}