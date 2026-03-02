/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in a width and height and draws an alternating rectangular checkerboard 
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int width,height;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;



    //Height = # of rows
    //Width = # of columns per row
    //Star = Whenever both row and col is odd or when both is even

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            if(((row % 2 == 0) && (col % 2 == 0)) || ((row % 2 == 1) && (col % 2 == 1)))
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