/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: vector<int> makeVector(int n);
                -Returns a vector of n integers that range from 0 to n-1

*/  

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//--- Function prototype ---
vector<int> makeVector(int n);

int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;


    vector<int> elements = makeVector(num);

    for(int e: elements)
    {
        cout << e << ' ';
    }

    return 0;
}

vector<int> makeVector(int n){
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    
    return v;
}
