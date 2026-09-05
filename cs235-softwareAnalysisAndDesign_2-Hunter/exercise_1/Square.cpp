#include "Square.hpp"
#include <cmath>

Square::Square(double edgeLength) 
    : Shape(4, edgeLength) {}

Square::Square() : Square(2) {}

double Square::area() const {
    return (std::pow(this->edgeLength() , 2));
}