/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Prints the top-right half of a square given the side length
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int sideLeng;

    cout << "Input side length: ";
    cin >> sideLeng;

    //Height = # of rows
    //Width = # of columns per row
    //Star = when col is greater than or equal to row 

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < sideLeng; row++)
    {
        for(int col = 0; col < sideLeng; col++)
        {
            if(col >= row)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }


    return 0;
}