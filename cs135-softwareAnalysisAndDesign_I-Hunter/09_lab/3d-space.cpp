/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-16
Updated:     2026-3-16
Description:  Define a function: length() 
                -Receives the coordinates of a point P passed as a pointer
                -Computes the distance from the origin to the point P
              Define a function: Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
                -Returns the pointer of the point that is farther away from the origin
              Define a function: void move(Coord3D *ppos, Coord3D *pvel, double dt);
                -Gets the position and the velocity of an object
                -Compute object’s new coordinates after the time interval dt
                -Update the object’s position ppos with its new position coordinates
              Define a function: Coord3D* createCoord3D(double x, double y, double z);
                -Allocate memory and initialize a Coord3D object
              Define a function: void deleteCoord3D(Coord3D *p);
                -Free up memory using the delete keyword

*/

// #include "Coord3D.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//---Classes ---
class Coord3D{
public:
    double x;
    double y;
    double z;
};

//--- Function prototype ---
double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);


int main(){

    Coord3D pointN = {10, 20, 30};
    cout << length(&pointN) << endl; 

    //---Task B
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?

    //---Task C
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;

    //---Task E
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    return 0;
}


double length(Coord3D *p){
    return sqrt(((p->x * p->x) + (p->y * p->y) + (p->z * p->z)));
}


Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    return (length(p1) > length(p2)) ?  p1 : p2;
}


void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;
}


Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *coordinate = new Coord3D;

    coordinate->x = x;
    coordinate->y = y;
    coordinate->z = z;
    
    return coordinate;
}


void deleteCoord3D(Coord3D *p){
    delete p;
}