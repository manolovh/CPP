#include <iostream>
#include "CustomArray.hpp"

int main()
{
    int a1[50] = { 2, 3, 6, 7, 8, 10 };
    int a2[50] = { 2, 4, 6, 8, 10, 11 };
    Array arr1 = { a1, 50, 6 };
    Array arr2 = { a2, 50, 6 };

    Array *arr3 = arr1.make_union(&arr2);
    Array *arr4 = arr1.get_intersection(&arr2);
    Array* arr5 = arr1.get_difference(&arr2);

    for (int i = 0; i < arr5->get_length(); i++)
    {
        std::cout << (*arr5)[i] << " ";
    }
}
