/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: void gogeta(vector<int> &goku, vector<int> &vegeta)
                -Appends elements of the second vector into the first 
                -Empties the second vector

*/  

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//--- Function prototype ---
void gogeta(vector<int> &goku, vector<int> &vegeta);

int main(){

    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
    
    cout << "Vector 1: \n";
    for(int v : v1)
    {
        cout << v << ' ';
    }

    cout << "\nVector 2: \n";
    for(int v: v2)
    {
        cout << v << ' ';
    }


    return 0;
}

void gogeta(vector<int> &goku, vector<int> &vegeta){
    int size1 = goku.size();
    int size2 = vegeta.size();

    for(int i = 0; i < size2; i++)
    {
        goku.push_back(vegeta.at(i));
    }
    vegeta.clear();

}