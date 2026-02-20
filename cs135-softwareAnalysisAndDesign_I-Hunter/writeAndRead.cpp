/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-20
Updated:     2026-2-20
Description: The program carries our the following task:
                1.Open a file with the name hello.txt.
                2.Store the message “Hello, World!” in the file.
                3.Close the file.
                4.Open the same file again.
                5.Read the message into a string variable and print it.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;


int main(){

    //Part 1
    ofstream writer;
    writer.open("hello.txt");

    if(writer.fail())
    {
        cerr << "File cannot be opened!" << endl;
        exit(1);  
    }

    //Part 2
    writer << "Hello, World!";

    //Part 3
    writer.close();
    // cout << "Data written to log.txt successfully." << endl;

    
    //Part 4
    ifstream reader;
    reader.open("hello.txt");

    if(reader.fail())
    {
        cerr << "File cannot be opened!" << endl;
        exit(1);     
    }

    //Part 5
    string fileText;

    getline(reader, fileText);

    cout << fileText;


    return 0;
}