/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Reads in a year and month and prints the number of days in that month
                -Taking into account of leap years
*/

#include <iostream>

using namespace std;

int main(){

    int year;
    int month;
    int days = 28;

    //Reads in a year and month
    cout << "Enter year: ";
    cin >> year;

    cout << "Enter month: ";
    cin >> month;

    //Months 1,3,5,7,8,10,12 have 31 days
    //Months 4,6,9,11 have 30 days
    //Month 2 , if leap year = 29 else = 28 days

    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        days = 30;
    }
    else if (month == 2)
    {
        if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            days = 29;
        }
    }
    else 
    {
        days = 31;
    }

    cout << days << " days";

    return 0;
}