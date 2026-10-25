// RecQueue.hpp
// CSCI 235 -- Exercise 6: Recursion and Queues
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef RECQUEUE_HPP
#define RECQUEUE_HPP

#include <queue>
#include <vector>

// Every function below must be RECURSIVE: do not use a loop (for, while) to
// do the repeating that a recursive call is supposed to do.
//
// The only queue operations you need are front(), back(), push(), pop(),
// empty() and size() from std::queue<int>.

// Task A -- Move the front element to the back, k times.
// Example: q = [1 2 3 4 5], k = 2  ->  q = [3 4 5 1 2].
// Precondition: k >= 0. If q is empty, nothing happens. Afterwards the
// elements of q are the same ones, in the rotated order.
void rotate(std::queue<int>& q, int k);

// Task B -- Reverse the order of the elements of q, in place.
// Example: q = [1 2 3 4] -> q = [4 3 2 1]. An empty or one-element queue is
// left alone. No other container (no vector, no stack) may be used: the
// recursion's own call stack does the remembering.
void reverseQueue(std::queue<int>& q); 

// Task C -- The "hot potato" game. The people in q are standing in a circle,
// front of the queue first. Each round, the potato is passed k times (the
// person at the front moves to the back, k times, exactly as in rotate()),
// and then the person now at the front is OUT of the game (removed). Rounds
// repeat until only one person is left. Return that person's value.
//
// Example: q = [1 2 3 4 5], k = 2.
//   Round 1: pass twice ([3 4 5 1 2]), remove 3.   q = [4 5 1 2]
//   Round 2: pass twice ([1 2 4 5]),   remove 1.   q = [2 4 5]
//   Round 3: pass twice ([5 2 4]),     remove 5.   q = [2 4]
//   Round 4: pass twice ([2 4]),       remove 2.   q = [4]    -> returns 4
//
// With k = 0 the potato is never passed: the front person leaves every round.
//
// Preconditions: q is not empty, 0 <= k <= 100. When the call returns,
// q holds exactly one element, the winner.
// You may call your own rotate() from Task A, but then Task C inherits any
// bug that Task A has.
int hotPotato(std::queue<int>& q, int k);

// Task D -- The same game as a formula. People are numbered 0, 1, ..., n-1
// in queue order. Return the NUMBER (0-based position in the original
// queue) of the person who wins. Recursive definition:
//   n == 1:  the only person, position 0, wins.
//   n  > 1:  see the handout.
// Preconditions: n >= 1, 0 <= k <= 100.
// Check: if q holds the values 1..n in order, then
//   hotPotato(q, k) == survivorPosition(n, k) + 1.
int survivorPosition(int n, int k);

#endif