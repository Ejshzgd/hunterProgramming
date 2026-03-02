/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Asks the user for two dates and prints out: 
                            - Which basin: East, West had the higher elevation or if they equal
                            - For each day in the interval
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){

    string startDate, endDate;

    cout << "Enter starting date: ";
    cin >> startDate;

    cout << "Enter ending date: ";
    cin >> endDate;

    
    fstream open("Current_Reservoir_Levels.tsv");
    if(open.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }


    string junk;
    getline(open,junk);

    
    string date;
    bool withinInterval;
    double eastSt, westSt;

    //East storage = 3 column
    //West storage = 5 column
    while(open >> date >> junk >> eastSt >> junk >> westSt)
    {

        if(date == startDate || withinInterval)
        {
            withinInterval = true;
            if(eastSt < westSt)
            {
                cout << date << " West" << endl;
            }
            else if(westSt < eastSt)
            {
                cout << date << " East" << endl;
            }
            else
            {
                cout << date << " Equal" << endl;
            }
        }


        if(date == endDate)
        {
            withinInterval = false;
        }

        open.ignore(INT_MAX,'\n');

    }


    return 0;
}