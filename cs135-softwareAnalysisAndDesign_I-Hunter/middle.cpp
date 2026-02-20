/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-20
Updated:     2026-2-20
Description: Write a function: string middle(string str)
                -Returns the middle char if length is odd
                -Return the two middle chars if length is even
*/

#include <iostream>
#include <string>

using namespace std;


//--- Function prototype ---
string middle(string str);


int main(){

    string word;

    cout << "Enter a string: ";
    getline(cin,word);


    cout << "The middle char/chars are: " << middle(word);

    return 0;
}


string middle(string str){
    int strLen = str.length();

    if(strLen % 2 == 0)     //If length is even, take the 2 middle chars
    {
        return str.substr((strLen/2)-1,2);
    }
    return str.substr(strLen/2,1);
    
}

