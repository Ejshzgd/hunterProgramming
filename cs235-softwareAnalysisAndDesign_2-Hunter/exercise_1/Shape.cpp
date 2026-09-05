#include "Shape.hpp"

Shape::Shape()
    : numEdges_(1), edgeLength_(1) {
}

Shape::Shape(int numEdges, double edgeLength)
    : numEdges_(numEdges > 0 ? numEdges : 1),
      edgeLength_(edgeLength > 0 ? edgeLength : 1) {
}

int Shape::numEdges() const {
    return numEdges_;
}

double Shape::edgeLength() const {
    return edgeLength_;
}

double Shape::area() const {
    return 0;   // placeholder for a general Shape
}

double Shape::perimeter() const {
    return numEdges_ * edgeLength_;
}

https://tong-yee.github.io/235/fall_2026/exercises/ex1_shape_triangle_square.html