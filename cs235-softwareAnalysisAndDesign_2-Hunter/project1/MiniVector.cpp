#include "MiniVector.hpp"


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

    data_ = new int[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;
    
    for(int i = 0; i <= size_; i++)
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

    for(int i = 0; i <= size_; i++)
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


