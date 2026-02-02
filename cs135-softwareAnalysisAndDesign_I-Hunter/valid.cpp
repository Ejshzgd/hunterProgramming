/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Asks the user to input an integer in the range 0 < n < 100 
                    -Re-prompts if outside that range
*/

#include <iostream>

using namespace std;

int main(){

    int num;

    //Reads in the first integer
    cout << "Please enter an integer: ";
    cin >> num;

    //Re-prompts if outside the range
    while((num <= 0) || (num >= 100))
    {
        cout << "Please re-enter: ";
        cin >> num;
    }

    cout << "Number squared is " << num*num;

    return 0;
}