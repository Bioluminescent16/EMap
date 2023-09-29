#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, char> encryptionMap;

void initializeEncryptionMap(){
  for(char c = 'a'; c <= 'z'; ++c){
    encryptionMap[c] = 'z' - (c - 'a');
  }
}

string encrypt(string plaintext){
  for(char& c : plaintext){
    if(isalpha(c)){
      char lowercaseC = tolower(c);
      if(encryptionMap.count(lowercaseC) > 0){
        c = islower(c) ? encryptionMap[lowercaseC] : toupper(encryptionMap[lowercaseC]);
      }
    }
  }
  return plaintext;
}

string decrypt(string ciphertext){
  return encrypt(ciphertext); // Decryption is the same as encryption in this case
}

int main() {
  initializeEncryptionMap();

  string input;
  cout << "Enter a word or phrase: ";
  getline(cin, input);

  string encrypted = encrypt(input);
  cout << "Encrypted: " << encrypted << endl;

  string decrypted = decrypt(encrypted);
  cout << "Decrypted: " << decrypted << endl;

  return 0;
}
