// RecQueue.cpp
// CSCI 235 -- Exercise 6: Recursion and Queues
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.

#include "RecQueue.hpp"

// Task A
void rotate(std::queue<int>& q, int k) {
    if(k == 0 || q.empty())
    {
        return;
    }

    q.push(q.front());
    q.pop();

    rotate(q,k-1);

}

// Task B
void reverseQueue(std::queue<int>& q) {
    if(q.empty() || q.front() == q.back())
    {
        return;
    }

    int oldFront = q.front();
    q.pop();

    reverseQueue(q);
    q.push(oldFront);   

}

// Task C
int hotPotato(std::queue<int>& q, int k) {
    if(q.front() == q.back())
    {
        return q.front();
    }

    rotate(q,k);
    q.pop();
    hotPotato(q,k);

    return q.front();
}

// Task D
int survivorPosition(int n, int k) {
    if(n == 1)
    {
        return 0;
    }

    int pos = (survivorPosition(n-1, k) + k + 1 ) % n;
    return pos;
}