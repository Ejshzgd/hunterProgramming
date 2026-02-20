/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-18
Updated:     2026-2-18
Description: Implements Vigenere cipher, replace each letter in the plaintext with a letter based on the keyword's position to shift down the alphabet
                    -Alphabet wraps around
                    -Preserve case
                    -Leave any non-alphabetic characters unchanged
                    -Assume that the "keyword" contains only lowercase
*/

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
string encryptVigenere(string plaintext, string keyword);



int main(){

    string plainText,keyWord;

    cout << "Enter plaintext: ";
    getline(cin,plainText);
    cout << "Enter keyword: ";
    cin >> keyWord;

    cout << "Ciphertext: " << encryptVigenere(plainText,keyWord);


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


//a = shift 0 , z = shift 25
string encryptVigenere(string plaintext, string keyword){
    string vigenereText;
    int plainTextLeng = plaintext.length();
    int keywordLength = keyword.length()-1;     
    int counter = 0;        //The index of keyword

    for(int i = 0; i < plainTextLeng; i++)
    {
        char letter = plaintext[i];

        //Checks to see if char is an alphabet
        //If yes, shift the letter based on the keyword's index - 97
        //a = shift 0 , b = shift 1, c = shift 2 ...
        if(isAbc(letter))       
        {
            vigenereText += shiftChar(letter,keyword[counter]-97);
            counter++;
        }
        else
        {
            vigenereText += letter;         
        }


        if(counter > keywordLength)        //Once it's out of bound, loops back to the first index
        {
            counter = 0;
        }
    }

    return vigenereText;

}