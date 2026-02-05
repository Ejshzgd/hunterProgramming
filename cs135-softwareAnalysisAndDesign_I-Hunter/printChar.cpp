/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in a word and prints each character of the word on a separate line
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    string word;
    
    cout << "Enter a word: ";
    cin >> word;


    int wordLeng = word.length();
    for(int i = 0; i < wordLeng; i++)
    {
        cout << word[i] << endl;
    }


    return 0;
}