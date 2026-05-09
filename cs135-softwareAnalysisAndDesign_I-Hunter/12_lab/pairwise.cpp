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

using namespace std;

//--- Function prototype ---
vector<int> sumPairWise(vector<int>& v1, vector<int>& v2);

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> v3 = sumPairWise(v1, v2); // returns [5, 7, 3]

    for(int v : v3) {
        cout << v << ' ';
    }

    cout << endl;
    return 0;
}

//--- Function implementation ---
vector<int> sumPairWise(vector<int>& v1, vector<int>& v2) {
    vector<int> v3;
    int sizeV1 = v1.size();
    int sizeV2 = v2.size();
    int smallerSize = (sizeV1 < sizeV2) ? sizeV1 : sizeV2;
    int largerSize = (sizeV1 > sizeV2) ? sizeV1 : sizeV2;

    // sum overlapping elements
    for(int i = 0; i < smallerSize; i++) {
        v3.push_back(v1[i] + v2[i]);
    }

    // append remaining elements from the longer vector
    if(sizeV1 > sizeV2) {
        for(int i = smallerSize; i < largerSize; i++) v3.push_back(v1[i]);
    } else {
        for(int i = smallerSize; i < largerSize; i++) v3.push_back(v2[i]);
    }

    return v3;
}