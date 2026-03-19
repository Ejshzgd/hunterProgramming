/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Creates an array for 10 integers and lets the user fill in the values
                - Be default, the values are set to 1
                - If index is out of range, the program exits
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){

    string myDate;

    cout << "Enter date: ";        //in MM/DD/YYYY format
    cin >> myDate;


    //Attempts to read in a .tsv file
    ifstream open("Current_Reservoir_Levels.tsv");

    if(open.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }


    //Stores in the header
    string junk;
    getline(open,junk);


    //Parses till the end
        //If date is found, prints out the east basin storage or else nothing
    string date;
    double eastSt;

    while((open >> date >> eastSt))
    {
        if(myDate == date)
        {
            cout << "East basin storage: " << eastSt << " billion gallons";
        }
        open.ignore(INT_MAX, '\n');
    }
    open.close();


    return 0;
}