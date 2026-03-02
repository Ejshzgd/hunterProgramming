/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Reads a year number and prints whether it's a leap or common year
                - Based on the modern Gregorian calendar
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int year;
    string result;

    //Reads in a year number
    cout << "Enter year: ";
    cin >> year;

    //Leap year if divisible by 4 and not a century year
    //Leap year if divisible 400 and is a century year
    if(year % 4 != 0)
    {
        result = "Common year";
    }
    else if(year % 100 != 0)
    {
        result = "Leap year";
    }
    else if(year % 400 != 0)
    {
        result = "Common year";
    }
    else
    {
        result = "Leap year";
    }

    cout << result;

    return 0;
}

