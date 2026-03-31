/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-30
Updated:     2026-3-30
Description: Simulates a circuit for controlling lights that has switches
             Each switch can be up or down, and the light can be on or off
             Provide member functions:
                -int get_first_switch_state(); //0 for down, 1 for up
                -int get_second_switch_state();
                -int get_lamp_state(); //0 for off, 1 for on
                -void toggle_first_switch();
                -void toggle_second_switch();

*/

//--Libraries
#include <iostream>
#include <string>

//--Namespaces
using namespace std;

//---Classes ---
class Circuit {
private:
    int first_switch;
    int second_switch;
    int lamp_state;
public:
    Circuit();

    int get_first_switch_state();

    int get_second_switch_state();

    int get_lamp_state();

    void toggle_first_switch();

    void toggle_second_switch();
};

//--Defining Circuit
Circuit::Circuit(){
    first_switch = 0;
    second_switch = 0;
    lamp_state = 0;
}

int Circuit::get_first_switch_state(){
    return first_switch;
}

int Circuit::get_second_switch_state(){
    return second_switch;
}

int Circuit::get_lamp_state(){
    return lamp_state;
}

void Circuit::toggle_first_switch(){
    first_switch = !first_switch;
    lamp_state = first_switch ^ second_switch;
}

void Circuit::toggle_second_switch(){
    second_switch = !second_switch;
    lamp_state = first_switch ^ second_switch;
}


int main(){


    return 0;
}