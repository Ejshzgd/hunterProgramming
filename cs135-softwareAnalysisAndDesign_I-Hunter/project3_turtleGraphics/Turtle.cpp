#include "Turtle.hpp"
#include <string>
#include <iostream>

using namespace std;

ostream& operator<<(std::ostream& os, Direction heading){
    switch (heading) {
        case Direction::EAST: return os << "EAST";
        case Direction::WEST: return os << "WEST";
        case Direction::SOUTH: return os << "SOUTH";
        case Direction::NORTH: return os << "NORTH";
        default: return os << "Unknown";
    }
}

void Turtle::reset(){
    pen = Pen::UP;
    heading = Direction::EAST;
    row = 0;
    col = 0;
}

bool Turtle::isPenUp() const{
    if(pen == Pen::UP)
    {
        return true;
    }
    return false;
}

void Turtle::liftUpPen(){
    pen = Pen::UP;
}

void Turtle::putDownPen(){
    pen = Pen::DOWN;
}

void Turtle::move(int steps){
    switch (heading) {
        case Direction::EAST: 
            col += steps;
            break;
        case Direction::WEST: 
            col -= steps;
            break;
        case Direction::SOUTH: 
            row += steps;
            break;
        case Direction::NORTH: 
            row -= steps;
            break;
    }
}

void Turtle::turnLeft(){
    switch (heading) {
        case Direction::EAST: 
            heading = Direction::NORTH;
            break;
        case Direction::WEST: 
            heading = Direction::SOUTH;
            break;
        case Direction::SOUTH: 
            heading = Direction::EAST;
            break;
        case Direction::NORTH: 
            heading = Direction::WEST;
            break;
    }   
}

void Turtle::turnRight(){
    switch (heading) {
        case Direction::EAST: 
            heading = Direction::SOUTH;
            break;
        case Direction::WEST: 
            heading = Direction::NORTH;
            break;
        case Direction::SOUTH: 
            heading = Direction::WEST;
            break;
        case Direction::NORTH: 
            heading = Direction::EAST;
            break;
    }   
}

void Turtle::setRow(int row){
    this->row = row;
}

void Turtle::setCol(int col){
    this->col = col;
}

int Turtle::getRow() const{
    return row;
}

int Turtle::getCol() const{
    return col;
}

void Turtle::setHeading(Direction heading){
    this->heading = heading;
}

Direction Turtle::getHeading() const{
    return heading;
}