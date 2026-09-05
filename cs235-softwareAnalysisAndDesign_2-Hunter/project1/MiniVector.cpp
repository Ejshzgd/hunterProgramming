#include "MiniVector.hpp"

MiniVector& MiniVector::operator=(const MiniVector& other){
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;

    return *this;
}

