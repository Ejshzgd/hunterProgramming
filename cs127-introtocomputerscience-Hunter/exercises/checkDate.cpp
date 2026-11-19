// #Name: Carey Jiang
// #Email: carey.jiang65@myhunter.cuny.edu
// #Date: December 18, 2024
// #This programs  asks the user for a year, and continue asking until the number entered that is 2018 or earlier.

#include <iostream>

int main(){
std::cout << "Enter year: ";
int year = -1;
std::cin >> year;

    while( year > 2019)
    {
        std::cout << "Year must be 2018 or earlier" << "\n";
        std::cout << "Enter year: ";
        std::cin >> year;
    }

    std::cout << "You entered:  " << year;
    return 0;
}
