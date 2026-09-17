#include "PointerPractice.hpp"
#include <climits>
#include <algorithm>

//Task A
TaskAAnswers taskA_pointerExpressions(int arr[]){
    TaskAAnswers a;
    int* p = arr;

    a.starArr = *arr;
    a.arrBracket0 = arr[0];
    a.starArrPlus1 = *(arr+1);
    a.arrBracket1 = arr[1];
    a.arrPlus1 = arr+1;
    a.addrArrBracket1 = &arr[1];
    a.starP = *p;
    a.pBracket0 = p[0];
    a.starPPlus2 = *(p+2);
    a.pBracket2 = p[2];
    a.arrPlus1EqualsAddrArrBracket1 = arr + 1 == &arr[1];
    a.starArrPlus2EqualsArrBracket2 = *(arr + 2) == arr[2];

    return a;
}

//Task B
int* allocate(std::size_t size){
    return new int[size]{};

}

//Task C
int* lastMinimum(int* arr, std::size_t size){
    if(size == 0){
        return nullptr;
    }

    int min = arr[size-1];
    int *minPointer = &min;
    bool allSame = true;
    for(std::size_t i = size-1; i-- > 0;)
    {
        if(min != arr[i])
        {
            allSame = false;
        }

        if(arr[i] < min)
        {
            min = arr[i];
            minPointer = &arr[i];
        }
    }

    return allSame ? &arr[size-1] : minPointer;
}

//Task D
void reverse(int* arr, std::size_t size){
    if (size < 2){
        return;
    }

    int* left = arr;
    int* right = arr + size - 1;

    while(left < right)
    {
        std::swap(*left, *right);

        left++;
        right--;
    }

}

//Task E
void swapValues(int* a, int* b){
    int aValue = *a;
    *a = *b;
    *b = aValue;
}


void swapPointers(int** a, int** b){
    int* aPointVal = *a;
    *a = *b;
    *b = aPointVal;
}

//Task F
bool isPalindrome(const int* arr, std::size_t size){
    if (size < 2){
        return true;
    }

    bool isPali = true;
    const int* left = arr;
    const int* right = arr + size - 1;

    while(left < right && isPali)
    {
        if(*left != *right){
            isPali = false;
        }

        left++;
        right--;
    }

    return isPali;
}

