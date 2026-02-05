/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Reads in three names and prints them each on a new line
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    string names;
    
    cout << "Enter three names: " << endl;

    for(int i = 0; i < 3; i++)
    {
        string tempName;
        cin >> tempName;
        names += tempName + "\n";
    }

    cout << names;

    return 0;
}