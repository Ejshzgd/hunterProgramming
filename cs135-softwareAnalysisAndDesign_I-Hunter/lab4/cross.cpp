/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in a size (size x size) and prints a diagonal cross
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int size;

    cout << "Input size: ";
    cin >> size;


    //Star = When row and col are the same or when row and col add up to the size-1 
    //                                                              cause we're starting at 0

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            if((row == col) || (row + col == size-1))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << '\n';
    }


    return 0;
}