/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-17
Updated:     2026-3-17
Description: Define a function: Particle* createParticle(double x, double y, double z, double vx, double vy, double vz);
                -Dynamically allocate memory for a particle and initialize it
             Define a function: void setVelocity(Particle *p, double vx, double vy, double vz);
                -Set its velocity to (vx, vy, vz)
             Define a function: Coord3D getPosition(Particle *p);
                -Get its current position
             Define a function: void move(Particle *p, double dt);
                -Update particle's position after elapsed time dt
             Define a function: void deleteParticle(Particle *p);
                -Delete all memory allocated for the particle passed by pointer
*/

// #include "Coord3D.h"
// #include "Particle.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//---Classes ---
class Particle{
public:
    double Xposition;
    double Yposition;
    double Zposition;

    double Xvelocity;
    double Yvelocity;
    double Zvelocity;
};


class Coord3D{
public:
    double x;
    double y;
    double z;
};

//--- Function prototype ---
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);
Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);


int main(){

    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;

    while(time < 3.0){
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);

    return 0;
}


Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    Particle* part = new Particle;
    *part = {x,y,z,vx,vy,vz};

    return part;
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


void setVelocity(Particle *p, double vx, double vy, double vz){
    p->Xvelocity = vx;
    p->Yvelocity = vy;
    p->Zvelocity = vz;
}


Coord3D getPosition(Particle *p){
    return *createCoord3D(p->Xposition , p->Yposition , p->Zposition);
}


void move(Particle *p, double dt){
    p->Xposition += p->Xvelocity * dt;
    p->Yposition += p->Yvelocity * dt;
    p->Zposition += p->Zvelocity * dt;
}


void deleteParticle(Particle *p){
    delete p;
}