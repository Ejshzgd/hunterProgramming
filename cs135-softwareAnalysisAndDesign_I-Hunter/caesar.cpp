/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-09
Updated:     2026-2-09
Description: Implement Caesar cipher, replace each letter in the plaintext with a letter some fixed number of positions down the alphabet
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


int main(){

    string plainText, cipherText;
    int shift;

    cout << "Plaintext: ";
    getline(cin, plainText);
    cout << "Enter shift: ";
    cin >> shift;


    int plainTextLeng = plainText.length();
    for(int i = 0; i < plainTextLeng; i++)
    {
        char letter = plainText[i];
        if(letter >= 65 && letter <= 90)
        {
            cipherText += shiftUpperChar(letter, shift);
        }
        else if(letter >= 97 && letter <= 122)
        {
            cipherText += shiftLowerChar(letter, shift);
        }
        else
        {
            cipherText += letter;
        }
    }


    cout << "Ciphertext: " << cipherText;

    return 0;
}



//A-Z (65-90) , a-z (97,122)
// A helper function to shift one character by rshift for uppercase letters
char shiftUpperChar(char c, int rshift){
    if(c + rshift > 90)
    {
        return (c+rshift)-26;
    }
    return (c+rshift);

}


// A helper function to shift one character by rshift for lowercase letters
char shiftLowerChar(char c, int rshift){
    if(c + rshift > 122)
    {
        return (c+rshift)-26;
    }
    return (c+rshift);
}

