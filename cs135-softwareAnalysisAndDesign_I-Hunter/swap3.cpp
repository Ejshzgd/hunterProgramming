/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-20
Updated:     2026-2-20
Description: Write a function: void sort3(int& a, int& b, int& c)
                - Given 3 integers, sort them in ascending order
*/

#include <iostream>

using namespace std;

//--- Function prototype ---
void sort3(int& a, int& b, int& c);


int main(){

    int num1 = 3, num2 = 2, num3 = 1;

    cout << "--Original Values--" << endl;
    cout << "Num1: " << num1 << " Num2: " << num2 << " Num3: " << num3 << endl;

    sort3(num1,num2,num3);

    cout << "--After Swap--" << endl;
    cout << "Num1: " << num1 << " Num2: " << num2 << " Num3: " << num3 << endl;


    return 0;
}



// - if a > b, swap a and b 
// - else leaves everything unchanged
void sort2(int& a, int& b){

    int temp;

    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

}


void sort3(int& a, int& b, int& c){

    sort2(a,b);
    sort2(a,c);
    sort2(b,c);

}