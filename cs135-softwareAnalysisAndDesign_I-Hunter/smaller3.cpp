/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-1-29
Updated:     2026-1-29
Description: Reads three integers from the user and prints the smaller value.
*/

#include <iostream>

using namespace std;

int main(){

    // Read three integers from the user
    int a,b,c,d;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    cout << "Enter the third number: ";
    cin >> c;

    // Compute the smallest number
    if((a < b) && (a < c))
    {
        d = a;
    }
    else if((b < a) && (b < c))
    {
        d = b;
    }
    else
    {
        d = c;
    }

    // Print the result
    cout << "The smaller of the three is " << d << endl;


    return 0;
}