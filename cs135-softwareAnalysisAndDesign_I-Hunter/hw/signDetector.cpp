/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads an integer and prints whether it's positive, negative, or zero
*/

#include <iostream>

using namespace std;

int main(){

    int num;

    cout << "Enter an integer: ";
    cin >> num;

    if(num < 0)
    {
        cout << "Negative";
    }
    else if(num > 0)
    {
        cout << "Positive";
    }
    else
    {
        cout << "Zero";
    }

    return 0;
}