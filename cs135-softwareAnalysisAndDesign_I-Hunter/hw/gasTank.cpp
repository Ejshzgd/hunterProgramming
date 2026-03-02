/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-03
Updated:     2026-2-03
Description: Reads in
                - Number of gallons of gas in the tank
                - Fuel efficiency in miles per gallon
                - Price of gas per gallon
            Prints the cost per 100 miles and how far the car can go
*/  

#include <iostream>

using namespace std;

int main(){

    double numGas, fuelEfficiency, price;

    cout << "Please enter the number of gallons of gas in the tank: ";
    cin >> numGas;

    cout << "Please enter the fuel efficiency in miles per gallon: ";
    cin >> fuelEfficiency;

    cout << "Please enter the price of gas per gallon: ";
    cin >> price;

    //Calculations

    double cost, distance;

    cost = (100/fuelEfficiency) * price;
    distance = numGas * fuelEfficiency;

    cout << "The cost per 100 miles is $" << cost << endl;
    cout << "Based on the current gas, the car can still travel " << distance << " miles";

    return 0;
}