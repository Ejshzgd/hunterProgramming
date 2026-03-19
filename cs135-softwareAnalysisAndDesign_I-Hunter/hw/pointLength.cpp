/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a structure Point with X & Y coordinate
             Define a function: double distance(Point a, Point b)
                -Computes the distance from a to b

*/  

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//--Struct
struct Point
{
    double x;
    double y;
};

//--- Function prototype ---
double distance(Point a, Point b);

int main(){

    Point a = {1.0,2.0} , b = {3.0,4.0};

    cout << "The distance between Point a and Point b is: " << distance(a,b);


    return 0;
}


double distance(Point a, Point b){
    return sqrt((pow((b.x-a.x),2) + pow((b.y-a.y),2)));
}