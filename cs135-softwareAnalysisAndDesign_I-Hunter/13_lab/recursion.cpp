/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: void printRange(int left, int right);
                -Prints all numbers in range left <= x <= right, separated by spaces
                -Using only recursion
             Define a function: int sumRange(int left, int right);
                -Computes the sum of all numbers in range left <= x <= right
                -Using only recursion

*/  

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
void printRange(int left, int right);
int sumRange(int left, int right);


int main(){

    //--Tast A
    printRange(-2, 10);

    //--Task B
    int x = sumRange(1, 3);
    cout << "This is " << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   // 52

    return 0;
}


void printRange(int left, int right){
    if(left == right)
    {
        cout << left;
    }

    if(left < right)
    {
        cout << left << ' ';
        printRange(left+1,right);
    }
}




int sumRange(int left, int right){

    if(left == right)
    {
        return left++;
    }

    if(left < right)
    {
        return left += sumRange(left++,right);
    }

    return left;
}