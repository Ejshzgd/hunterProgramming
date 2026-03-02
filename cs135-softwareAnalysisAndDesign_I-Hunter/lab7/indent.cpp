/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-02
Updated:     2026-3-02
Description: Reads the input line by line
                -Keep track of how many blocks is currently open at the beginning of each line
                -Add that number of tabs '\t' at the beginning of each line
*/

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
int countChar(string line, char c);
string removeLeadingSpaces(string line);


int main(){

    string sourceFile, updatedFile;
    int indentLevel = 0;;


    while(getline(cin, updatedFile)){

    updatedFile = removeLeadingSpaces(updatedFile);

    int openCount  = countChar(updatedFile, '{');
    int closeCount = countChar(updatedFile, '}');

    // Count how many '}' appear at the very start
    int leadingClose = 0;
    while(leadingClose < updatedFile.length() && updatedFile[leadingClose] == '}')
    {
        leadingClose++;
    }

    // Decrease indent only for leading '}'
    indentLevel -= leadingClose;

    if(indentLevel < 0)
        indentLevel = 0;

    // Print with current indent
    for(int i = 0; i < indentLevel; i++)
    {
        cout << '\t';
    }
    
    cout << updatedFile << endl;

    // Adjust remaining braces AFTER printing
    indentLevel += openCount;
    indentLevel -= (closeCount - leadingClose);

    if(indentLevel < 0)
        indentLevel = 0;
    }   


    return 0;

}


//Returns the number of occurrences of the character 'c'
int countChar(string line, char c){
    int lineLeng = line.length();
    int counter = 0;

    for(int i = 0; i < lineLeng; i++)
    {
        if(line[i] == c)
        {
            counter++;
        }
    }

    return counter;
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