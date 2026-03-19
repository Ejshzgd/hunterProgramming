/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: vector<int> goodVibes(const vector<int>& v);
                -Return a vector with only the positive integers in the same order

*/  

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--- Function prototype ---
vector<int> goodVibes(const vector<int>& v);

int main(){

    vector<int> elements{1,2,-1,3,4,-1,6};
    cout << "Original values: " << '\n';
    for(int e: elements)
    {
        cout << e << ' ';
    }
    
    cout << '\n' << "Updated values: " << '\n';
    vector<int> updatedElements = goodVibes(elements); // returns [1,2,3,4,6]
    for(int e: updatedElements)
    {
        cout << e << ' ';
    }


    return 0;
}

vector<int> goodVibes(const vector<int>& v){
    vector<int> temp;
    int size = v.size();

    for(int i = 0; i < size; i++)
    {
        if(v.at(i) >= 0)
        {
            temp.push_back(v.at(i));
        }
    }

    return temp;
}