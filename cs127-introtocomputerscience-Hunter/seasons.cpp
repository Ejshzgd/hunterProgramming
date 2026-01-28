// #Name: Carey Jiang
// #Email: carey.jiang65@myhunter.cuny.edu
// #Date: December 18, 2024
// #This program Write a C++ program that asks the user for the month of the year (as a number), and prints
// "Happy Winter" if it is strictly before 3 or strictly larger than 11,
// "Happy Spring" if it is 3 or greater, but strictly before 7, and
// "Happy Summer" if it is 7 or greater, but strictly before 9, and
// "Happy Fall" otherwise.

#include <iostream>
using namespace std;

int main() {
    int month;
    
    // Ask the user for the month number
    cout << "Enter month (as a number): ";
    cin >> month;

    // Check which season the month corresponds to
    if (month < 3 || month > 11) {
        cout << "Happy Winter" << endl;
    }
    else if (month >= 3 && month < 7) {
        cout << "Happy Spring" << endl;
    }
    else if (month >= 7 && month < 9) {
        cout << "Happy Summer" << endl;
    }
    else {
        cout << "Happy Fall" << endl;
    }

    return 0;
}
