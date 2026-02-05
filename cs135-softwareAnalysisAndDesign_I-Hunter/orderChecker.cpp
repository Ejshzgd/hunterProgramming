/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-04
Updated:     2026-2-04
Description: Reads in three integers and prints whether it's increasing, decreasing, or neither
                    //strictly increasing or strictly decreasing
*/

#include <iostream>

using namespace std;

int main(){

    int num1,num2,num3;

    cout << "Enter three integers: " << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;


    if(num1 < num2 && num2 < num3)
    {
        cout << "Increasing!";
    }
    else if(num1 > num2 && num2 > num3)
    {
        cout << "Decreasing!";
    }
    else
    {
        cout << "Neither!";
    }

    return 0;
}