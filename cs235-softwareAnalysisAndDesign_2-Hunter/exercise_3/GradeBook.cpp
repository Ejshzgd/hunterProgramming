// GradeBook.cpp
// CSCI 235 -- Exercise 3: The Big Three
// Complete the TODO sections below and submit this file.

#include "GradeBook.hpp"

GradeBook::GradeBook(std::size_t capacity)
    : grades_(new double[capacity]{}), count_(0), capacity_(capacity) {
}

void GradeBook::addGrade(double grade) {
    if (count_ < capacity_) {
        grades_[count_] = grade;
        ++count_;
    }
    // If the book is full, the grade is silently dropped.
    // The optional growTo() function can increase the capacity.
}

std::size_t GradeBook::count() const { return count_; }
std::size_t GradeBook::capacity() const { return capacity_; }

// --------------------------------------------------------------
// TODO -- Task A: GradeBook::~GradeBook()
GradeBook::~GradeBook(){

    delete[] grades_;
}
// TODO -- Task B: GradeBook::GradeBook(const GradeBook& other)
GradeBook::GradeBook(const GradeBook& other): grades_(new double[other.capacity_]),
                                                count_(other.count_), 
                                                capacity_(other.capacity_){

    for(std::size_t i = 0; i < count_; i++)
    {
        grades_[i] = other.grades_[i];
    }
}
// TODO -- Task C: GradeBook& GradeBook::operator=(const GradeBook& other)
GradeBook& GradeBook::operator=(const GradeBook& other){

    if(this == &other)
    {
        return *this;
    }

    delete[] grades_;

    grades_ = new double[other.capacity_];
    count_ = other.count_;
    capacity_ = other.capacity_;

    for(std::size_t i = 0; i < count_; i++)
    {
        grades_[i] = other.grades_[i];
    }

    return *this;
}
// TODO -- Task D: double GradeBook::average() const
double GradeBook::average() const{
    if(count_ == 0)
    {
        return 0.0;
    }

    double sum = 0;
    for(std::size_t i = 0; i < count_; i++)
    {
        sum+=grades_[i];
    }

    return (sum/count_);
}
// TODO -- Task E (optional): void GradeBook::growTo(std::size_t newCapacity)
void GradeBook::growTo(std::size_t newCapacity){
    if(newCapacity < capacity_)
    {
        return;
    }

    double* newGradeArr = new double[newCapacity];
    capacity_ = newCapacity;

    for(std::size_t i = 0; i < count_; i++)
    {
        newGradeArr[i] = grades_[i];
    }

    delete[] grades_;
    grades_ = newGradeArr;
}