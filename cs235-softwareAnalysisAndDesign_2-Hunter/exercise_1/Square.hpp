#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape.hpp"

class Square : public Shape {

public:
    Square();

    Square(double edgeLength);

    double area() const override;

};

#endif