// GradeBookDemo.cpp
// CSCI 235 -- Exercise 3: The Big Three
//
// A small driver so you can compile and run your GradeBook.cpp locally
// and see it in action before submitting. This file is PROVIDED for
// your own testing -- you do NOT submit it, and Gradescope does not
// use it; Gradescope has its own, more thorough checks.
//
// Compile and run with:
//   g++ -std=c++17 GradeBook.cpp GradeBookDemo.cpp -o demo
//   ./demo

#include <iostream>

#include "GradeBook.hpp"

int main() {
    std::cout << "=== Copy constructor ===\n";
    GradeBook a(3);
    a.addGrade(90);
    a.addGrade(80);

    GradeBook b = a;
    b.addGrade(70);

    std::cout << "a.count() = " << a.count() << "   (expect 2)\n";
    std::cout << "a.average() = " << a.average() << "   (expect 85)\n";
    std::cout << "b.count() = " << b.count() << "   (expect 3)\n";
    std::cout << "b.average() = " << b.average() << "   (expect 80)\n";

    std::cout << "\n=== Copy assignment ===\n";
    GradeBook c(2);
    c.addGrade(100);
    c = a;
    c.addGrade(60);

    std::cout << "a.count() = " << a.count() << "   (expect 2, unchanged)\n";
    std::cout << "a.average() = " << a.average() << "   (expect 85, unchanged)\n";
    std::cout << "c.count() = " << c.count() << "   (expect 3)\n";
    std::cout << "c.average() = " << c.average() << "   (expect approx 76.67)\n";

    std::cout << "\n=== Self-assignment ===\n";
    std::size_t beforeCount = c.count();
    double beforeAvg = c.average();
    c = c;
    std::cout << "c.count() unchanged? "
              << (c.count() == beforeCount ? "true" : "false") << "   (expect true)\n";
    std::cout << "c.average() unchanged? "
              << (c.average() == beforeAvg ? "true" : "false") << "   (expect true)\n";

    std::cout << "\n=== Task E (optional): growTo ===\n";
    GradeBook d(2);
    d.addGrade(10);
    d.addGrade(20);
    d.growTo(4);
    d.addGrade(30);
    std::cout << "d.capacity() = " << d.capacity() << "   (expect 4)\n";
    std::cout << "d.count() = " << d.count() << "   (expect 3)\n";
    std::cout << "d.average() = " << d.average() << "   (expect 20)\n";

    return 0;
}