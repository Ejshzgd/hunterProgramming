/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-09
Updated:     2026-2-09
Description: Read in a series of ints and print out their sum
                - End the input by pressing ctrl z in Windows
*/

#include <iostream>

using namespace std;

int main(){

    int temp,sum;
    
    cout << "Enter a series of ints: ";

    while(cin >> temp)
    {
        sum += temp;
    }

    cout << "Sum = " << sum;


    return 0;
}