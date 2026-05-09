/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-19
Updated:     2026-3-19
Description: Define a function: void printRange(int left, int right);
                -Prints all numbers in range left <= x <= right, separated by spaces
                -Using only recursion
             Define a function: int sumRange(int left, int right);
                -Computes the sum of all numbers in range left <= x <= right
                -Using only recursion
             Define a function: int sumArray(int *arr, int size);
                 -Receives an array (as a pointer to its first element) and the size of the array
                 -Return the sum of its elements
             Define a function: bool isAlphanumeric(string s);
                 -Returns true if all characters in the string are letters and digits
             Define a function: bool nestedParens(string s);
                 -Returns true if the string is a sequence of nested parentheses
             Define a function: bool divisible(int *prices, int size);
                 -Returns true if the collection is divisible, and false otherwise
                 -The prices are provided in the array prices, and size is the number of items in the array.

*/  

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//--- Function prototype ---
void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool divisible(int *prices, int size);


int main(){

    //--Tast A
    printRange(-2, 10);

    //--Task B
    int x = sumRange(1, 3);
    cout << "\nThis is " << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   // 52

    
    int arr[] = {12,17,-5,3,7,-15,27,5,12,-21};

    int sum1 = sumArray(arr, 10); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 42
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34


    return 0;
}


void printRange(int left, int right){
    if(left == right)
    {
        cout << left;
    }

    if(left < right)
    {
        cout << left << ' ';
        printRange(left+1,right);
    }
}


int sumRange(int left, int right){

    if(left == right)
    {
        return left++;
    }

    if(left < right)
    {
        return left += sumRange(left+1,right);
    }

    return 0;
}


int sumArrayInRange(int *arr, int left, int right, int total){
    total += arr[left];

    if(left == right)
    {
        return total;
    }

    if(left < right)
    {
        return sumArrayInRange(arr,left+1,right,total);
    }

    return 0;
}


int sumArray(int *arr, int size){
    return sumArrayInRange(arr,0,size-1,0);
}


bool isAlphanumeric(string s) {
    if (s.empty()) {
        return true;
    }

    if (!isalnum(s[0])) {
        return false;
    }

    return isAlphanumeric(s.substr(1));
}

bool nestedParens(string s) {
    if (s.empty()) {
        return true;
    }

    if (s.length() < 2) {
        return false;
    }

    if (s[0] != '(' || s[s.length() - 1] != ')') {
        return false;
    }

    return nestedParens(s.substr(1, s.length() - 2));
}

bool helper(int *prices, int size, int index, int target) {
    if (target == 0) {
        return true;
    }

    if (index == size || target < 0) {
        return false;
    }

    if (helper(prices, size, index + 1, target - prices[index])) {
        return true;
    }

    if (helper(prices, size, index + 1, target)) {
        return true;
    }

    return false;
}

int sumRecursive(int *prices, int size, int index) {
    if (index == size) {
        return 0;
    }
    return prices[index] + sumRecursive(prices, size, index + 1);
}

bool divisible(int *prices, int size) {
    int total = sumRecursive(prices, size, 0);

    if (total % 2 != 0) {
        return false;
    }

    return helper(prices, size, 0, total / 2);
}

