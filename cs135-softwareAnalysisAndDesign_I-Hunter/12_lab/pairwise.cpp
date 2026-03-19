/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)
                -Returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors

*/  

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//--- Function prototype ---
vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2);

int main(){

    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> v3 = sumPairWise(v1, v2); // returns [5, 7, 3]

    for(int v : v3)
    {
        cout << v << ' ';
    }

    return 0;

}

vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2){
    vector<int> v3;
    int sizeV1 = v1.size() , sizeV2 = v2.size();
    int smallerSize = -1 ,  largerSize = -1;
    (sizeV1 >= sizeV2) ? (smallerSize = sizeV2 , largerSize = sizeV1) 
                       : (smallerSize = sizeV1 , largerSize = sizeV2);

    for(int i = 0; i < smallerSize; i++)
    {
        int sum = v1.at(i) + v2.at(i);
        v3.push_back(sum);
    }


    if(sizeV1 == sizeV2)
    {
        return v3;
    }


    for(int i = smallerSize; i < largerSize; i++)
    {
        if(largerSize == sizeV1)
        {
            v3.push_back(v1.at(i));
        }
        else
        {
            v3.push_back(v2.at(i));
        }
    }

    return v3;
}
