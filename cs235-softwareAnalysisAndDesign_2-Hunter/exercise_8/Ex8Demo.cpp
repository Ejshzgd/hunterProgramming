// Ex8Demo.cpp
// CSCI 235 -- Exercise 8: Shunting-Yard Trace
//
// Provided file -- do not submit this. Build it with:
//
//     g++ -std=c++17 -g Postfix.cpp Ex8Demo.cpp -o ex8demo
//     ./ex8demo
//
// The expected output is in demo_output.txt. Your output should match it
// exactly once all four tasks are done.

#include "Postfix.hpp"

#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

static std::string join(std::queue<std::string> q) {
    std::string s;
    while (!q.empty()) {
        s += q.front();
        q.pop();
        if (!q.empty()) { s += " "; }
    }
    return s;
}

int main() {
    std::cout << "=== Task A: tokenize ===\n";
    for (const char* text : {"3 + 4 * 2", "12+3*(4-1)", "(7)"}) {
        std::vector<std::string> t = tokenize(text);
        std::cout << "  \"" << text << "\" -> " << t.size() << " tokens:";
        for (const std::string& tok : t) { std::cout << " [" << tok << "]"; }
        std::cout << "\n";
    }

    std::cout << "\n=== Task B: evalPostfix ===\n";
    for (const char* text : {"3 4 2 * +", "3 4 + 2 *", "8 3 - 2 -", "7 2 /"}) {
        std::queue<std::string> q;
        for (const std::string& tok : tokenize(text)) { q.push(tok); }
        std::cout << "  " << text << "  =  " << evalPostfix(q) << "\n";
    }
    try {
        std::queue<std::string> q;
        for (const std::string& tok : tokenize("5 0 /")) { q.push(tok); }
        evalPostfix(q);
        std::cout << "  5 0 /  did not throw\n";
    } catch (const std::runtime_error& e) {
        std::cout << "  5 0 /  throws: " << e.what() << "\n";
    }

    std::cout << "\n=== Task C: toPostfix ===\n";
    for (const char* text : {"3 + 4 * 2", "(3 + 4) * 2", "8 - 3 - 2",
                             "5 + (1 + 2) * 4 - 3", "12 / (2 + 1) - 1"}) {
        std::cout << "  " << text << "  ->  " << join(toPostfix(tokenize(text))) << "\n";
    }

    std::cout << "\n=== Task D: evaluate ===\n";
    for (const char* text : {"3 + 4 * 2", "(3 + 4) * 2", "8 - 3 - 2",
                             "5 + (1 + 2) * 4 - 3", "12 / (2 + 1) - 1",
                             "7 / 2", "9 / 4", "(2 + 3) * (4 - 1)", "100/(5*4)"}) {
        std::cout << "  " << text << "  =  " << evaluate(text) << "\n";
    }
    return 0;
}