#include <iostream>
#include "CustomArray.hpp"

int main()
{
    int a1[50] = { 1, 3, 5, 7, 9 };
    int a2[50] = { 2, 4, 6, 8, 10 };
    Array arr1 = { a1, 50, 5 };
    Array arr2 = { a2, 50, 5 };

    Array* arr3 = arr1.merge(&arr2);

    for (int i = 0; i < 10; i++)
    {
        std::cout << (*arr3)[i] << " ";
    }
}
