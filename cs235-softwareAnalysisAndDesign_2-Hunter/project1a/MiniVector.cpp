#include "MiniVector.hpp"

#include <stdexcept>


bool MiniVector::empty() const{
    return (size_ == 0);
}

std::size_t MiniVector::size() const{
    return size_;
}

std::size_t MiniVector::capacity() const{
    return capacity_;
}


//Overloaded Constructor
MiniVector::MiniVector(std::size_t count): data_(new int[(count > 0) ? count : 2]{}),
                                            size_((count > 0) ? count : 0),
                                            capacity_((count > 0) ? count : 2){}


//Def Constructor
MiniVector::MiniVector(): MiniVector(0){}

//Destructor
MiniVector::~MiniVector(){

    delete[] data_;
}


//Overloaded Assignment Operator
MiniVector& MiniVector::operator=(const MiniVector& other){

    if(this == &other)
    {
        return *this;
    }

    delete[] data_;

    data_ = new int[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;
    
    for(std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }

    return *this;
}


//Copy constructor
MiniVector::MiniVector(const MiniVector& other){

    data_ = new int[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;

    for(std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }
}


int& MiniVector::operator[](std::size_t idx){
    return data_[idx];
}
    
const int& MiniVector::operator[](std::size_t idx) const{
    return data_[idx];
}

int& MiniVector::at(std::size_t idx){
    if(idx >= size())
    {
        throw std::out_of_range("Index is out of bounds!");
    }

    return data_[idx];
}

const int& MiniVector::at(std::size_t idx) const{
    if(idx >= size())
    {
        throw std::out_of_range("Index is out of bounds!");
    }

    return data_[idx];
}

void MiniVector::reserve(std::size_t newCapacity){
    if(newCapacity <= capacity_)
    {
        return;
    }

    int* newArray = new int[newCapacity];

    for(std::size_t i = 0; i < size_; ++i)
    {
        newArray[i] = data_[i];
    }

    delete[] data_;
    data_ = newArray;
    capacity_ = newCapacity;
}


void MiniVector::push_back(int value){
    if(size_ == capacity_)
    {
        reserve(2 * capacity_);
    }

    data_[size_] = value;
    size_++;
}

void MiniVector::pop_back(){
    if(!empty())
    {
        data_[size_] = 0;
        size_--;
    }
}

void MiniVector::clear(){
    size_ = 0;
}


