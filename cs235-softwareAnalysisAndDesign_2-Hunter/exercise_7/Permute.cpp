// Permute.cpp
// CSCI 235 -- Exercise 7: Permutations
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.

#include "Permute.hpp"

#include <utility>   // std::swap

// Task A
long long factorial(int n) {
    if(n == 0)
    {
        return 1;
    }
    
    return n * factorial(n-1);
}



// Task B
void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out) {
    // TODO:
    //   * base case: nothing left to arrange.
    //   * otherwise, for each choice for position k: put that choice at
    //     position k, recurse on the rest, then undo what you did so the next
    //     choice starts from the same vector.

    if(v.size() == k)
    {
        out.push_back(v);
        return;
    }

    int kValue = v[k];
    for(int i = static_cast<int>(k); i < v.size(); i++)
    {
        v[k] = v[i];
        v[i] = kValue;

        permute(v,k+1,out);

        v[i] = v[k];
        v[k] = kValue;
    }
}

// Task C
std::vector<std::vector<int>> allPermutations(std::vector<int> v) {
    std::vector<std::vector<int>> out;
    permute(v,0,out);

    return out;
}

// Task D
int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k) {
    int count = 0;
    std::vector<std::vector<int>> out;
    permute(v,k,out);

    for(std::vector<int> v : out)
    {
        bool derangement = true;
        for(int i = static_cast<int>(k); i < v.size(); i++)
        {
            if(v[i] == original[i])
            {
                derangement = false;
                break;
            }
        }

        if(derangement)
        {
            count++;
        }
    }

    return count;
    
}