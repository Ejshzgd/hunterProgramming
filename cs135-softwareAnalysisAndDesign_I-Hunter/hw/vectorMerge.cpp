/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-4-07
Updated:     2026-4-07
Description: Define a function: vector<int> merge_sorted(vector<int> a, vector<int> b);
                    - Vectors a & b are sorted 
                    - Merge vectors a & b and sort them
*/  

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//--- Function prototype ---
vector<int> merge_sorted(vector<int> a, vector<int> b);

//--- Function implementation ---
vector<int> merge_sorted(vector<int> a, vector<int> b){
    int aIndex = 0;
    int bIndex = 0;
    int aLeng = a.size();
    int bLeng = b.size();

    vector<int> c;

    while(aIndex < aLeng && bIndex < bLeng)
    {
        int aNum = a.at(aIndex);
        int bNum = b.at(bIndex);

        if(aNum < bNum)
        {
            c.push_back(aNum);
            aIndex++;
        }
        else
        {
            c.push_back(bNum);
            bIndex++;
        }
    }

    while(aIndex < aLeng)
    {
        int aNum = a.at(aIndex);
        c.push_back(aNum);
        aIndex++;
    }

    while(bIndex < bLeng)
    {
        int bNum = b.at(bIndex);
        c.push_back(bNum);
        bIndex++;
    }

    return c;

}

int main(){
    vector<int> a = {1,4,9,16};
    vector<int> b = {4,7,9,9,11};

    vector<int> c = merge_sorted(a,b);

    for(int num : c)
    {
        cout << num << ' ';
    }

    return 0;
}