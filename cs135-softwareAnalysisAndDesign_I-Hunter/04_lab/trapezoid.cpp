/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Prints an upside-down trapezoid of given width and height
                    - If input height is impossibly large for the given width
                                -then report, "Impossible shape!""
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int width, height;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    
    //Check if it's even or odd and then apply formula
    int maxHeight;
    if(width % 2 == 0)
    {
        maxHeight = (width-1)/2 + 1;
    }
    else
    {
        maxHeight = (width/2) + 1;
    }

    if(height > maxHeight)
    {
        cout << '\n' << "Impossible shape!";
        return 0;
    }


    //Height = # of rows
    //Width = # of columns per row
    //Star = whenever col # is greater than row #, but within the range of width-current row #

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            if((col >= row) && (col < width-row))
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