/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-09
Updated:     2026-2-09
Description: - Define the function: bool isDivisibleBy(int n, int d)
             - Define the function: bool isPrime(int n);
             - Define the function: int nextPrime(int n);
             - Define the function: int countPrimes(int a, int b);
             - Define the function: bool isTwinPrime(int n);
             - Define the function: int nextTwinPrime(int n);
             - Define the function: int largestTwinPrime(int a, int b);
                        - Added a helper function: int prePrime(int n);
                        - Added a helper function: int preTwinPrime(int n);
*/

#include <iostream>

using namespace std;

//--- Function prototypes ---
bool isDivisibleBy(int n, int d);
bool isPrime(int n);
int nextPrime(int n);
int prePrime(int n);
int countPrimes(int a, int b);
bool isTwinPrime(int n);
int nextTwinPrime(int n);
int preTwinPrime(int n);
int largestTwinPrime(int a, int b);



int main(){

    //Task A -- Implementing the function bool isDivisibleBy(int n, int d)
    int num1, num2;

    cout << "Enter dividend: ";
    cin >> num1;
    cout << "Enter divisor: ";
    cin >> num2;

    cout << (isDivisibleBy(num1,num2) ? "true, " + to_string(num1) + " is divisible by " + to_string(num2) : "false, " + to_string(num1) + " is NOT divisible by " + to_string(num2)) << endl;


    //Task B -- Implementing the function bool isPrime(int n);
    int num3;

    cout << "Enter an integer: ";
    cin >> num3;

    cout << (isPrime(num3) ? "true, " + to_string(num3) + " is prime!"  : "false, " + to_string(num3) + " is NOT prime!") << endl;


    //Task C -- Implementing the function int nextPrime(int n);
    int num4;

    cout << "Enter a prime integer: ";
    cin >> num4;

    cout << "The next prime integer is: " << nextPrime(num4) << endl;;


    //Task D -- Implementing the function int countPrimes(int a, int b);
    int num5, num6;

    cout << "Enter the lower range: ";
    cin >> num5;
    cout << "Enter the upper range: ";
    cin >> num6;

    cout << "There is " << countPrimes(num5,num6) << " prime numbers between " << num5 << " and " << num6 << endl; 


    //Task E -- Implementing the function bool isTwinPrime(int n);
    int num7;

    cout << "Enter a number: ";
    cin >> num7;

    cout << (isTwinPrime(num7) ? "true, " + to_string(num7) + " is a twin prime number!" : "false, " + to_string(num7) + " is NOT a twin prime number!" ) << endl;


    //Task F -- Implementing the function int nextTwinPrime(int n);
    int num8;

    cout << "Enter a number: ";
    cin >> num8;

    cout << "The next twin prime number is: " << nextTwinPrime(num8) << endl;

    
    //Task G -- Implementing the function int largestTwinPrime(int a, int b);
    int num9;
    int num10;

    cout << "Enter the lower range: ";
    cin >> num9;
    cout << "Enter the upper range: ";
    cin >> num10;

    int gResult = largestTwinPrime(num9,num10);
    cout << "The largest twin prime number in the interval a <= num <= b is: " << (gResult == -1) ? "NONE!" : to_string(gResult);

    

    return 0;
}


//--- Functions ---

//Return true: If n is divisible by d & false otherwise
//n % d = undefined
bool isDivisibleBy(int n, int d)
{
    if(d != 0 && n % d == 0)
    {
        return true;
    }

    return false;
}


//Return true: If n is prime and false otherwise
//Prime numbers are not divisible by any of the numbers from 2 to N−1
bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }

    for(int i = 2; i*i <= n; i++)
    {
        if(isDivisibleBy(n,i))
        {
            return false;
        }
    }

    return true;
}


//Returns the next smallest prime number greater than n
int nextPrime(int n)
{
    if(n < 2) return 2;

    int nextPrimeNum = n+1;
    
    while(!isPrime(nextPrimeNum))
    {
        nextPrimeNum++;
    }

    return nextPrimeNum;

}


//Returns the previous prime number
//Return -1 if there isn't a previous prime number
int prePrime(int n)
{
    if(n <= 2) return -1;

    int prePrimeNum = n-1;

    while(!isPrime(prePrimeNum))
    {
        prePrimeNum--;
    }

    return prePrimeNum;
}


//Return the number of prime numbers in the interval a <= num <= b
int countPrimes(int a, int b)
{
    int counter = 0;
    int num = nextPrime(a);

    if(isPrime(a))
    {
        counter++;
    }

    while(num <= b)
    {
        counter++;
        num = nextPrime(num);
    }

    return counter;
}


//Return true: If n is a twin prime and false otherwise
//Twin prime is either N-2 ir N+2 is also a prime number: 3, 5, 7, 11, 13, 17, 19, 29, 31 …
bool isTwinPrime(int n)
{
    if(isPrime(n) && (isPrime(n-2) || isPrime(n+2)))
    {
        return true;
    }

    return false;
}


//Return the next smallest twin prime number greater n
int nextTwinPrime(int n)
{
    int primeNum = n;

    do
    {
        primeNum = nextPrime(primeNum);
    }while(!isTwinPrime(primeNum));
    
    return primeNum;
}


//Return the previous twin prime number
//Return -1 if there isn't a previous twin prime number
int preTwinPrime(int n)
{
    if(n <= 3) return -1;

    int primeNum = n;

    do
    {
        primeNum = prePrime(primeNum);
    }while(!isTwinPrime(primeNum));

    return primeNum;
}

//Return the largest twin prime number in the interval a <= num <= b
//If there's no twin primes in the interval, then return -1.
int largestTwinPrime(int a, int b)
{   
    if(isTwinPrime(b)) return b;

    int primeNum = preTwinPrime(b);

    return (primeNum >= a) ? primeNum : -1;
}