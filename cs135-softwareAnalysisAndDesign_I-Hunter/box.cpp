/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in a width and height and draws a corresponding rectangle
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

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            cout << "*";
        }

        cout << '\n';
    }


    return 0;
}