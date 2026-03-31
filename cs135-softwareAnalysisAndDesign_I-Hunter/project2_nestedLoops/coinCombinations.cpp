/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-21
Updated:     2026-3-21
Description: Prompt the user to enter: 
                -an amount in dollars (as a decimal, e.g., 0.25)
                -the maximum number of cents (pennies) allowed in any combination
              Print all possible combinations of:
                -quarters (25¢), dimes (10¢), nickels (5¢), and cents (1¢) that sum to the specified amount
              Each valid combination must not exceed the user-defined maximum number of pennies 

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    double amount = 0.0;
    int maxCents = 0;

    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter maximum number of cents: ";
    cin >> maxCents;


    int maxQuarters = ceil(amount/0.25);

    int maxDimes = ceil(amount/0.10);

    int maxNickels = ceil(amount/0.05);
    
    int maxPennies = maxCents;

    int maxCombination[] = {maxPennies,  maxNickels , maxDimes , maxQuarters};
    int counter = 1;


    cout << "   quarters" << "   dimes" << "   nickels" << "   cents" << endl;

    if((amount == 0.0) || (maxQuarters*0.25 + maxDimes*0.10 + maxNickels*0.05 + maxCents*0.01 < amount))
    {
        cout << "no solution";
        return 0;
    }


    while(maxQuarters >= 0)
    {
        while(maxDimes >= 0)
        {
            while(maxNickels >= 0)
            {
                while(maxPennies >= 0)
                {
                    if(maxQuarters*0.25 + maxDimes*0.10 + maxNickels*0.05 + maxPennies*0.01 == amount)
                    {
                        cout << counter << ":\t" << maxQuarters << '\t' << maxDimes << '\t' << maxNickels << '\t' << maxPennies << endl;
                        counter++;
                    }
                    maxPennies--;
                }
                maxPennies = maxCombination[0];
                maxNickels--;
            }
            maxNickels = maxCombination[1];
            maxDimes--;
        }
        maxDimes = maxCombination[2];
        maxQuarters--;
    }

    return 0;
}