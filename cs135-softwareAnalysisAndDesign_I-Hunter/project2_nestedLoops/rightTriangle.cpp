/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-16
Updated:     2026-3-16
Description: Find all integer sets (a, b, hypotenuse) such that a^2 + b^2 = hypotenuse^2
                -Constraints: 1 ≤ a < b < hypotenuse
                -Format:
                    (a) Display the results in a numbered list.
                    (b) Each line must follow the format: Order: a b hypotenuse
                    (c) The Order must start at 1 and be immediately followed by a colon (:)

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    int maxHyp;
    
    cout << "Enter the maximum hypotenus: ";
    cin >> maxHyp;

    int order = 1;
    cout << '\n';
    for (int a = 1; a <= maxHyp; a++) 
    {
        for (int b = a+1; b <= maxHyp; b++) 
        {
            int c2 = a*a + b*b;
            int c = sqrt(c2);
            if (c*c == c2 && c <= maxHyp) 
            {
            cout << order << ": " << a << " " << b << " " << c << endl;
            order++;
            }
        }
    }


    return 0;
}