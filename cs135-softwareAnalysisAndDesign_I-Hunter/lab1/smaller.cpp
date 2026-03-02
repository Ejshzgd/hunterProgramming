/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-1-29
Updated:     2026-1-29
Description: Reads two integers from the user and prints the smaller value.
*/

#include <iostream>

using namespace std;

int main(){

    int a,b;

    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    cout << "The smaller of the two is " << ((a < b) ? a : b) << endl;


    return 0;
}