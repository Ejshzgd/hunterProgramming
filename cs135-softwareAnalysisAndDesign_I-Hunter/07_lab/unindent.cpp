/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-02
Updated:     2026-3-02
Description: Reads input from cin and prints out each input line with leading spaces removed
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//--- Function prototype ---
string removeLeadingSpaces(string line);


int main(){

    string sourceFile, updatedFile;


    while(getline(cin,updatedFile))
    {
        cout << removeLeadingSpaces(updatedFile) << endl;
    }


    return 0;

}


//Returns an updated string with no leading spaces
string removeLeadingSpaces(string line){
    string updatedString;
    int lineLeng = line.length();
    int start = 0;


    while(isspace(line[start]) && start < lineLeng)
    {
        start++;
    }

    updatedString = line.substr(start, lineLeng - start + 1);
    return updatedString;
}
