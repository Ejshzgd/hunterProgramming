/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Asks the user for two integers, upper and lower limit
                -Print out all integers within that range separated by spaces
                - Including lower limit and excluding upper 
*/

#include <iostream>

using namespace std;

int main(){

    int lower;
    int upper;

    //Reads in two integer for upper and lower limit
    cout << "Please enter L: ";
    cin >> lower;

    cout << "Please enter U: ";
    cin >> upper;

    for(int i = lower; i < upper; i++)
    {
        cout << i << " ";
    }

    return 0;
}