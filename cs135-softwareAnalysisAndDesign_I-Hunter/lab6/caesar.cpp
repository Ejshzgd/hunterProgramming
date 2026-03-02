/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-09
Updated:     2026-2-09
Description: Implements Caesar cipher, replace each letter in the plaintext with a letter some fixed number of positions down the alphabet
                    -Alphabet wraps around
                    -Preserve case
                    -Leave any non-alphabetic characters unchanged
*/

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
char shiftUpperChar(char c, int rshift);
char shiftLowerChar(char c, int rshift);
char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);


int main(){

    string plainPhrase;
    int shift;

    cout << "Plaintext: ";
    getline(cin, plainPhrase);
    cout << "Enter shift: ";
    cin >> shift;


    cout << "Ciphertext: " << encryptCaesar(plainPhrase,shift);

    return 0;
}



//A-Z (65-90)
// A helper function to shift one character by rshift for uppercase letters
char shiftUpperChar(char c, int rshift){
    if(c + rshift > 90)
    {
        return (c+rshift)-26;
    }
    return (c+rshift);

}


//a-z (97,122)
// A helper function to shift one character by rshift for lowercase letters
char shiftLowerChar(char c, int rshift){
    if(c + rshift > 122)
    {
        return (c+rshift)-26;
    }
    return (c+rshift);
}


// Returns the shifted character 
char shiftChar(char c, int rshift){
    if(c >= 65 && c <= 90)
    {
        return shiftUpperChar(c, rshift);
    }
    
    if(c >= 97 && c <= 122)
    {
        return shiftLowerChar(c, rshift);
    }

    return c;
}


// Returns the message encrypted in Caesar
string encryptCaesar(string plaintext, int rshift){
    string cipherText;
    int plainTextLeng = plaintext.length();

    for(int i = 0; i < plainTextLeng; i++)
    {
        char letter = plaintext[i];
        cipherText += shiftChar(letter,rshift);
    }

    return cipherText;
}
