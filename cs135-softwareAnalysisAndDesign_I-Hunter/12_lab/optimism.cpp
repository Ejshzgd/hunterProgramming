/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-4-7
Description: Define a function: vector<int> goodVibes(vector<int> v);
             - Return a vector with only the positive integers in the same order
*/  

#include <iostream>
#include <vector>

using namespace std;

//--- Function prototype ---
vector<int> goodVibes(vector<int> v);

int main() {
    vector<int> elements{1, 2, -1, 3, 4, -1, 6};

    cout << "Original values:\n";
    for (int e : elements) {
        cout << e << ' ';
    }
    
    cout << "\nUpdated values:\n";
    vector<int> updatedElements = goodVibes(elements); // returns [1,2,3,4,6]
    for (int e : updatedElements) {
        cout << e << ' ';
    }

    cout << endl;
    return 0;
}

//--- Function implementation ---
vector<int> goodVibes(vector<int> v) {
    vector<int> temp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {          // Only positive integers
            temp.push_back(v[i]);
        }
    }
    return temp;
}