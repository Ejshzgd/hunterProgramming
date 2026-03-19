/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-16
Updated:     2026-3-16
Description: Given a positive odd integer, prints out a diamond
                - Implements an input validation loop
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int size;
    
    cout << "Enter the size of a diamond as a positive odd integer: ";
    cin >> size;

    while(size <= 0 || size % 2 == 0 )
    {
        cout << "size needs to be a positive odd integer: ";
        cin >> size;
    }


    int middle = size / 2;
    cout << '\n';
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            int distance = abs(middle - row);
            if (col >= distance && col < size - distance)
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }


    return 0;
}