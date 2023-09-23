#include <iostream>
#include "CustomArray.hpp"

int main()
{
    int arr1[50] = { 1, 3, 5, 7, 9 };
    int arr2[50] = { 2, 4, 6, 8, 10 };
    Array arr1 = { arr1, 50, 5 };
    Array arr2 = { arr2, 50, 5 };

    Array* arr3 = arr1.merge(&arr2);
}
