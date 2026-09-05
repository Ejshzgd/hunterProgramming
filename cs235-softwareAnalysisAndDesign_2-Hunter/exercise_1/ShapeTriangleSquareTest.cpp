#include <iostream>
#include "Shape.hpp"
#include "Triangle.hpp"
#include "Square.hpp"

void printByPointer(Shape* spPtr);

int main() {
    // TODO 1:
    // Instantiate a Triangle named tri with edge length 6.
    Triangle tri(6);

    // TODO 2:
    // Instantiate a Square named sq with edge length 5.
    Square sq(5);


    // TODO 3:
    // Create an array named shapePtrs containing Shape pointers.
    // Store the addresses of tri and sq in the array.
    Shape* shapePtrs[] = {&tri , &sq};



    // TODO 4:
    // Determine the number of elements in shapePtrs.
    // You may use: sizeof(shapePtrs) / sizeof(shapePtrs[0])
    std::cout << "Size of shapePtrs array: " << sizeof(shapePtrs) / sizeof(shapePtrs[0]) << std::endl;

    // TODO 5:
    // Use a loop to call printByPointer() for every
    // element of shapePtrs.
    for(Shape* point : shapePtrs)
    {
        printByPointer(point);
    }


    return 0;
}

void printByPointer(Shape* spPtr) {
    // TODO 6:
    // Print the number of edges.
    std::cout << "Number of edges: " << spPtr->numEdges() << std::endl;

    // TODO 7:
    // Print the edge length.
    std::cout << "Edge length: " << spPtr->edgeLength() << std::endl;


    // TODO 8:
    // Print the perimeter.
    std::cout << spPtr->perimeter() << std::endl;


    // TODO 9:
    // Print the area.
    std::cout << spPtr->area() << std::endl;

}