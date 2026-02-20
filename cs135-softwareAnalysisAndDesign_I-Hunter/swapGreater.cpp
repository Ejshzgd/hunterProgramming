/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-20
Updated:     2026-2-20
Description: Write a function: void sort2(int& a, int& b)
                - if a > b, swap a and b 
                - else leaves everything unchanged
*/

#include <iostream>

using namespace std;

//--- Function prototype ---
void sort2(int& a, int& b);


int main(){

    int num1 = 2, num2 = 1;

    cout << "--Original Values--" << endl;
    cout << "Num1: " << num1 << " Num2: " << num2 << endl;

    sort2(num1,num2);

    cout << "--After Swap--" << endl;
    cout << "Num1: " << num1 << " Num2: " << num2;

    return 0;
}


void sort2(int& a, int& b){

    int temp;

    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

}