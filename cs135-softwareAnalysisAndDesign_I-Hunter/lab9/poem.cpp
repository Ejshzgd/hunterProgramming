/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-17
Updated:     2026-3-17
Description: Fix the program :/

*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;

    }
}