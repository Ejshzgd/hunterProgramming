/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Creates an array for 10 integers and lets the user fill in the values
                - Be default, the values are set to 1
                - If index is out of range, the program exits
*/

#include <iostream>

using namespace std;

int main(){

    //Initialize an array and set it's values to 1
    int myData[10];

    for(int i = 0; i < 10; i++)
    {
        myData[i] = 1;
    }

    //Reads in the first index and value
    int index = 0;
    int value = 1;

    do {

        myData[index] = value;

        for(int x : myData)
        {
            cout << x << " ";
        }
        cout << "\n";

        cout << "Input index: ";
        cin >> index;
    
        cout << "Input value: ";
        cin >> value;

    } while (index >= 0 && index <= 9);
    
    cout << "Index out of range. Exit.";

    return 0;
}