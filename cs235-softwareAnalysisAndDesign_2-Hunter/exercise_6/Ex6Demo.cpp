// Ex6Demo.cpp
// CSCI 235 -- Exercise 6: Recursion and Queues
//
// Provided file -- do not submit this. Build it with:
//
//     g++ -std=c++17 -g RecQueue.cpp Ex6Demo.cpp -o ex6demo
//     ./ex6demo
//
// The expected output is in demo_output.txt. Your output should match it
// exactly once all four tasks are done.

#include "RecQueue.hpp"

#include <iostream>
#include <queue>

static std::queue<int> make(int n) {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    return q;
}

static void print(std::queue<int> q) {      // by value: prints a copy
    std::cout << "[";
    bool first = true;
    while (!q.empty()) {
        std::cout << (first ? "" : " ") << q.front();
        first = false;
        q.pop();
    }
    std::cout << "]";
}

int main() {
    std::cout << "=== Task A: rotate ===\n";
    for (int k : {0, 1, 2, 5, 7}) {
        std::queue<int> q = make(5);
        rotate(q, k);
        std::cout << "  rotate [1 2 3 4 5] by " << k << ": ";
        print(q);
        std::cout << "\n";
    }

    std::cout << "\n=== Task B: reverseQueue ===\n";
    for (int n : {0, 1, 2, 6}) {
        std::queue<int> q = make(n);
        std::cout << "  ";
        print(q);
        reverseQueue(q);
        std::cout << " -> ";
        print(q);
        std::cout << "\n";
    }

    std::cout << "\n=== Task C: hotPotato ===\n";
    for (int k : {0, 1, 2}) {
        std::queue<int> q = make(5);
        int w = hotPotato(q, k);
        std::cout << "  5 people, k = " << k << ": winner " << w
                  << ", queue size afterwards " << q.size() << "\n";
    }

    std::cout << "\n=== Task D: survivorPosition ===\n";
    for (int k : {1, 2}) {
        std::cout << "  k = " << k << ":";
        for (int n = 1; n <= 7; ++n) {
            std::cout << " " << survivorPosition(n, k);
        }
        std::cout << "\n";
    }
    return 0;
}