/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-30
Updated:     2026-3-30
Description: Define a Rectangle class
             Provide a constructor with given width and height values
             Prove member functions:
                -double get_perimeter();
                -double get_area();
                -void resize(double factor); //Multiply the width and height by the given factor

*/

//--Libraries
#include <iostream>
#include <string>

//--Namespaces
using namespace std;

//---Classes ---
class Rectangle {
private:
    double width = 0;
    double height = 0;
public:
    Rectangle(double width, double height);

    double get_perimeter();

    double get_area();

    void resize(double factor);
       
};

//--Defining Circuit
Rectangle::Rectangle(double width, double height){
    this->width = width;
    this->height = height;
}

double Rectangle::get_perimeter(){
    return (width*2 + height*2);
}

double Rectangle::get_area(){
    return (width*height);
}

void Rectangle::resize(double factor){
    width *= factor;
    height *= factor;
}


int main(){


    return 0;
}