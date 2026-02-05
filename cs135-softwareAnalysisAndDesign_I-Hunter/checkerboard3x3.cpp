/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in a width and height and prints a checkerboard of 3-by-3 squares
                    -Works even if the input dimension is not a multiple of three
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
    //Star = 
    //      a = Row = {0,1,2,6,7,8...}, Col = {0,1,2,6,7,8...}
    //      b = Col = {3,4,5,9,10,11...}, Col = {3,4,5,9,10,11}
    //{K,K,K,D,D,D,...} -> 0 <= a % 6 <= 2 , 3 <= b % 6 <= c
    //(a%6)/3 = 0 , (b%6)/3 = 1  -> row # = col #


    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {

            if ((col % 6) / 3 == (row % 6) / 3)
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



            // if ((col % 6 <= 2) && (row % 6 <= 2))
            // {
            //     cout << '*';
            // }
            // else if((col % 6 >= 3 && col % 6 <= 5) && (row % 6 >= 3 && row % 6 <= 5))
            // {
            //     cout << '*';
            // }
            // else
            // {
            //     cout << ' ';
            // }   