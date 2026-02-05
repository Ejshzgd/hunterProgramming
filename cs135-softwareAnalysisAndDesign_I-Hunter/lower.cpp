/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Prints the bottom-left half of a square given the side length 
*/

#include<iostream>
#include<string>

using namespace std;

int main(){

    int sideLeng;

    cout << "Input side length: ";
    cin >> sideLeng;

        
    //Height = # of rows
    //Width = # of columns per row
    //Star = row # + 1

    cout << '\n' << "Shape:" << endl;
    for(int row = 0; row < sideLeng; row++)
    {
        for(int col = 0; col < row+1; col++)
        {
            cout << "*";
        }
        cout << '\n';
    }






    return 0;
}