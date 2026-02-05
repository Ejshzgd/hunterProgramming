/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Finds the minimum and maximum storage in East basin in 2018
                    - Specifically East basin in 2018
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cfloat>

using namespace std;

int main(){

    fstream open("Current_Reservoir_Levels.tsv");
    if(open.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    //Stores the header
    string junk;
    getline(open,junk);

    double temp;
    double min = DBL_MAX;
    double max = DBL_MIN;


    while(open >> junk >> temp)
    {
        if(temp > max)
        {
            max = temp;
        }

        if(temp < min)
        {
            min = temp;
        }

        open.ignore(INT_MAX,'\n');      //Ignores all other columns
    }
    open.close();

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;


    return 0;
}