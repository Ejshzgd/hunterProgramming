#include "TurtleGraphics.hpp"
#include <iostream>
#include <vector>

using namespace std;

TurtleGraphics::TurtleGraphics() {
    turtle.reset();
    floor = Floor();
}

TurtleGraphics::TurtleGraphics(int size) {
    turtle.reset();
    floor = Floor(size);
}

void TurtleGraphics::restart() {
    turtle.reset();
    floor.clear();
}

void TurtleGraphics::run() {
    restart();

    while (true) {
        int move;
        cin >> move;

        if (move == 9) {
            return;
        }

        if (move >= 1 && move <= 6) {
            processCommand(move, true, -1);
        }
    }
}

void TurtleGraphics::run(const vector<vector<int>>& commands) {
    restart();

    for (const vector<int>& v : commands) {
        if (v.size() == 1) {
            processCommand(v[0], false, -1);
        }
        else if (v.size() == 2) {
            processCommand(v[0], false, v[1]);
        }
    }
}

const Floor& TurtleGraphics::getFloor() const {
    return floor;
}

const Turtle& TurtleGraphics::getTurtle() const {
    return turtle;
}

void TurtleGraphics::processCommand(int command, bool inputFromConsole, int numSteps) {
    switch (command) {

        case 1:
            turtle.liftUpPen();
            break;

        case 2:
            turtle.putDownPen();
            break;

        case 3:
            turtle.turnRight();
            break;

        case 4:
            turtle.turnLeft();
            break;

        case 5: {
            int steps;

            if (inputFromConsole) {
                cin >> steps;
            } else {
                steps = numSteps;
            }

            for (int i = 0; i < steps; i++) {
                turtle.move(1);

                // ONLY draw if pen is down AFTER move
                if (!turtle.isPenUp()) {
                    floor.mark(turtle.getRow(), turtle.getCol(), '*');
                }
            }
            break;
        }

        case 6:
            cout << floor.to_string();
            break;

        case 9:
            return;
    }
}