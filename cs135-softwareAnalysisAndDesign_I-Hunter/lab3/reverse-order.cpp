/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Prints out all the west basin elevations within the interval in reverse order 
                    - Starting from later date to earlier date
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){

    string startDate, endDate;

    cout << "Enter earlier date: ";
    cin >> startDate;

    cout << "Enter later date: ";
    cin >> endDate;


    fstream open("Current_Reservoir_Levels.tsv");
    if(open.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }


    string junk;
    getline(open,junk);


    string date, westSt, result;
    bool withinInterval;


    while(open >> date >> junk >> junk >> junk >> westSt)
    {
        if(date == startDate || withinInterval)
        {
            withinInterval = true;

            //output for escape char are shown when printed
            string temp = '\n' + date + " " + westSt + " ft";      
            result = temp + result;        //prepend
        }

        if(date == endDate)
        {
            withinInterval = false;
        }

        open.ignore(INT_MAX,'\n');
    }

    cout << result;


    return 0;
}