#include "Triangle.hpp"
#include <cmath>


Triangle::Triangle(double edgeLength) 
    : Shape(3, edgeLength){

}

Triangle:: Triangle() : Triangle(2) {}

double Triangle::area() const{
    return ((std::sqrt(3)/4) * std::pow(this->edgeLength(),2));
}
