/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-09
Updated:     2026-2-09
Description: Asks the user to input a line of text & print all characters from the input line together with their ASCII codes on separate lines
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string word;
    cout << "Input: ";
    getline(cin, word);            //Input might include spaces


    for(int i = 0; i < word.length(); i++)
    {
        char letter = word[i];
        cout << letter << ' ' << int(letter) << endl;
    }


    return 0;
}