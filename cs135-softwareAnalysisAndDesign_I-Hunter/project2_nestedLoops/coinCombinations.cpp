/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-21
Updated:     2026-3-21
Description: 

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
    if(maxQuarters > maxCents)
    {
        maxQuarters = maxCents;
    }

    int maxDimes = ceil(amount/0.10);
    if(maxDimes > maxCents)
    {
        maxDimes = maxCents;
    }

    int maxNickels = ceil(amount/0.05);
    if(maxNickels > maxCents)
    {
        maxNickels = maxCents;
    }
    
    int maxPennies = maxCents;

    int maxCombination = maxPennies*1 + maxNickels*10 + maxDimes*100 + maxQuarters*1000;
    int counter = 1;


    cout << "   quarters" << "   dimes" << "   nickels" << "   cents" << endl;

    if((maxCents == 0 && amount > 0.0) || (maxCents*0.25 + maxCents*0.10 + maxCents*0.05 + maxCents*0.01 < amount))
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
                maxPennies = (maxCombination) % 10;
                maxNickels--;
            }
            maxNickels = (maxCombination / 10) % 10;
            maxDimes--;
        }
        maxDimes = (maxCombination / 100) % 10;
        maxQuarters--;
    }

    return 0;
}