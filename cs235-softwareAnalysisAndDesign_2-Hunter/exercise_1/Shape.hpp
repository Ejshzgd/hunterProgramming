#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
public:
    Shape();
    Shape(int numEdges, double edgeLength);

    int numEdges() const;
    double edgeLength() const;

    virtual double area() const;
    double perimeter() const;

private:
    int numEdges_;
    double edgeLength_;
};

#endif