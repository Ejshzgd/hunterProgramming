/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: void sort2(double* p, double* q) 
                -Receives two pointers and sorts the values to which they point
                -If you call sort2(&x, &y) then x <= y after the call
*/  

#include <iostream>
#include <string>

using namespace std;

//--- Function prototype ---
void sort2(double* p, double* q);

int main(){

    double test1 = 2.0, test2 = 1.0;

    cout << "Test1 Original Value: " << test1 << " Test2 Original Value: " << test2 << endl;

    sort2(&test1,&test2);

    cout << "Test1 Sorted Value: " << test1 << " Test2 Sorted Value: " << test2 << endl;

    return 0;
}


void sort2(double* p, double* q){

    if (*p > *q)
    {
        double temp = *p;
        *p = *q;
        *q = temp;
    }

}