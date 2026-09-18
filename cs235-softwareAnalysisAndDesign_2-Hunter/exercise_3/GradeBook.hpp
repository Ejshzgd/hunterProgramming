// GradeBook.hpp
// CSCI 235 -- Exercise 3: The Big Three
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <cstddef>

// GradeBook stores a list of numeric grades in a dynamically
// allocated array -- the same "owns a heap array" shape as MiniVector,
// simplified here to a single array of doubles.
class GradeBook {
public:
    explicit GradeBook(std::size_t capacity);   // provided

    // ---- The Big Three: implement these in GradeBook.cpp ----
    GradeBook(const GradeBook& other);              // Task B
    GradeBook& operator=(const GradeBook& other);    // Task C
    ~GradeBook();                                       // Task A

    void addGrade(double grade);    // provided -- appends if room remains
    double average() const;         // Task D
    std::size_t count() const;      // provided
    std::size_t capacity() const;   // provided

    // Task E (OPTIONAL PRACTICE -- not graded)
    void growTo(std::size_t newCapacity);

private:
    double* grades_;
    std::size_t count_;
    std::size_t capacity_;
};

#endif