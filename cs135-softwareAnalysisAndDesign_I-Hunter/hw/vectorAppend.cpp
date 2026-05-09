/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-4-07
Updated:     2026-4-07
Description: Define a function: vector<int> append(vector<int> a, vector<int> b);
                    - Returns a vector that appends 'b' to 'a' while allowing duplicates

*/  

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//--- Function prototype ---
vector<int> append(vector<int> a, vector<int> b);

//--- Function implementation ---
vector<int> append(vector<int> a, vector<int> b){
    vector<int> concat = a;

    for(int num : b)
    {
        concat.push_back(num);
    }

    return concat;
}

int main(){
    vector<int> a = {1,2,3};
    vector<int> b = {3,4,5};

    vector<int> c = append(a,b);

    for(int num : c)
    {
        cout << num << ' ';
    }

    return 0;
}