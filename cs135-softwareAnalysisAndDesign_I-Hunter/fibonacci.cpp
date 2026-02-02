/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-02
Updated:     2026-2-02
Description: Uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59)
*/

#include <iostream>

using namespace std;

int main(){

    int fib[60];

    fib[0] = 0;
    fib[1] = 1;

    //Formula: Current = (Current - 1) + (Current - 2)
    for(int i = 2; i < 60; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    //Prints out the result
    for(int f : fib)
    {
        cout << f << endl;
    }

    return 0;
}