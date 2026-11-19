// Permute.hpp
// CSCI 235 -- Exercise 7: Permutations
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef PERMUTE_HPP
#define PERMUTE_HPP

#include <cstddef>
#include <vector>

// All four functions work on vectors of DISTINCT ints (no repeated values).
// Every function is recursive. The loops you may use are the one that tries
// each choice for the current position; the repetition itself comes from
// the recursive calls.

// Task A -- n! = n * (n-1) * ... * 1, with 0! = 1.
// Precondition: 0 <= n <= 20 (20! is the largest factorial a long long holds).
long long factorial(int n);

// Task B -- append to out every arrangement of v[k], v[k+1], ..., v[size-1],
// keeping v[0..k-1] where they are. Each arrangement is appended as a full
// copy of v. Do this IN PLACE: swap elements of v, recurse, and undo the swap.
//
// Calling permute(v, 0, out) produces every permutation of v.
//
// The order of the permutations in out is part of the specification: for each
// position k, try the choices v[k], v[k+1], ... in that order, by swapping the
// chosen element into position k. When permute returns, v must be exactly as
// it was when the call began, and anything already in out must still be there.
void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out);

// Task C -- return all permutations of v, in the order Task B produces them.
// v is passed BY VALUE, so the caller's vector is never touched.
std::vector<std::vector<int>> allPermutations(std::vector<int> v);

// Task D -- count the permutations of original in which NO element is in the
// position it started in. (original[j] must not appear at index j.)
//
// v starts as a copy of original. The call counts arrangements of
// v[k..size-1], keeping v[0..k-1] where they are, and returns the count.
// v must be exactly as it was when the call began once the call returns.
//
// Calling countDerangements(v, original, 0) with v == original counts all of them.
// Examples: 3 distinct values -> 2, 4 -> 9, 1 -> 0, 0 values -> 1.
int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k);

#endif