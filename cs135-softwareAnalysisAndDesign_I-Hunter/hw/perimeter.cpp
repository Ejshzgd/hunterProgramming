/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a structure Triangle that contains three Point members
             Define a function that computes the perimeter of a Triangle

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

struct Triangle
{
    Point a;
    Point b;
    Point c;
};

//--- Function prototype ---
double distance(Point a, Point b);
double perimeter(Triangle tri);

int main(){

    Point a = {1.1,2.2} , b = {1.2,1.3} , c = {1.4,1.5};
    Triangle tri = {a,b,c};

    cout << "The perimeter of tri is: " << perimeter(tri);

    return 0;
}

double distance(Point a, Point b){
    return sqrt((pow((b.x-a.x),2) + pow((b.y-a.y),2)));
}

double perimeter(Triangle tri){
    return distance(tri.a,tri.b) + distance(tri.b,tri.c) + distance(tri.a,tri.c);
}