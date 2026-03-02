/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-19
Updated:     2026-2-19
Description: Undo Vigenere & Caesar encryption
*/

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);


int main(){

    string plainText;

    cout << "Enter plaintext: ";
    getline(cin,plainText);


    //Caesar decryption
    cout << "\n= Caesar =" << endl;

    string caesarText;
    int shiftValue;

    cout << "Enter shift: ";
    cin >> shiftValue;
    cout << "Ciphertext: ";
    cin.ignore();
    getline(cin,caesarText);


    cout << "Decrypted: " << decryptCaesar(caesarText,shiftValue) << endl;


    //Vigenere decryption
    cout << "\n= Vigenere =" << endl;

    string keyWord, vigenereText;

    cout << "Enter keyword: ";
    cin >> keyWord;
    cout << "Ciphertext: ";
    cin.ignore();
    getline(cin,vigenereText);


    cout << "Decrypted: " << decryptVigenere(vigenereText,keyWord);


    return 0;
}



//Returns true if it's an alphabet and false otherwise
bool isAbc(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    return false;
}


//A-Z (65-90)
// A helper function to shift one character by rshift for uppercase letters
char shiftUpperChar(char c, int rshift){
    if(c + rshift > 90)
    {
        return (c+rshift)-26;
    }

    if(c + rshift < 65)
    {
        return (c+rshift)+26;
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

    if(c + rshift < 97)
    {
        return (c+rshift)+26;
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


//Decrypts Caesar text by shiftting to the left 
string decryptCaesar(string ciphertext, int rshift){
    string decryptText;
    int ciphertextLength = ciphertext.length();

    for(int i = 0; i < ciphertextLength; i++)
    {
        char letter = ciphertext[i];
        decryptText += shiftChar(letter, -rshift);
    }

    return decryptText;

}


//Decrypts Vigenere text by shiftting to the left 
string decryptVigenere(string ciphertext, string keyword)
{
    string decryptText;
    int ciphertextLeng = ciphertext.length();
    int keywordLength = keyword.length()-1;     
    int counter = 0;        //The index of keyword

    for(int i = 0; i < ciphertextLeng; i++)
    {
        char letter = ciphertext[i];

        //Checks to see if char is an alphabet
        //If yes, shift the letter based on the keyword's index - 97
        //a = shift 0 , b = shift 1, c = shift 2 ...
        if(isAbc(letter))       
        {
            decryptText += shiftChar(letter,-(keyword[counter]-97));
            counter++;
        }
        else
        {
            decryptText += letter;         
        }


        if(counter > keywordLength)        //Once it's out of bound, loops back to the first index
        {
            counter = 0;
        }
    }

    return decryptText;
}