#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"
class Triangle : public Shape {

public:
    Triangle();

    Triangle(double edgeLength);

    double area() const override;

};

#endif