/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-20
Updated:     2026-2-20
Description: Write a function: bool equals(int a[], int a_size, int b[], int b_size)
                - Returns true: 
                    - If both arrays have the same size and the same arrangement of elems
                - Returns false otherwise
*/

#include <iostream>

using namespace std;

//--- Function prototype ---
bool equals(int a[], int a_size, int b[], int b_size);

int main(){

    int size1 = 3;
    int arr1[] = {1,2,3};
    int arr2[] = {1,2,3};

    cout << (equals(arr1,size1,arr2,size1) ? ("Same array!") : ("Different array!")) << endl;


    int arr3[] = {1,2,3,4};
    int size2 = 4;
    int arr4[] = {1,2,3};
    int size3 = 3;

    cout << (equals(arr3,size2,arr4,size3) ? ("Same array!") : ("Different array!"));


    return 0;
}



bool equals(int a[], int a_size, int b[], int b_size){
    if(a_size != b_size) return false;

    for(int i = 0; i < a_size; i++)
    {
        if(a[i] != b[i]) return false;
    }

    return true;
}
