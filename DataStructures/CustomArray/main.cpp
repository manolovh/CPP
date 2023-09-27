#include <iostream>
#include "CustomArray.hpp"

int main()
{
    int a1[50] = { 1, 3, 5, 7, 9 };
    int a2[50] = { 2, 4, 6, 8, 10 };
    Array arr1 = { a1, 50, 5 };
    Array arr2 = { a2, 50, 5 };

    std::cout << "0" << std::endl;
    // Array *arr3 = arr1.make_union(&arr2);
    Array* arr4 = arr1.get_intersection(&arr2);
    Array* arr5 = arr1.get_intersection(&arr2);

    std::cout << "0" << std::endl;
    std::cout << arr4->get_length() << std::endl;
    for (int i = 0; i < arr4->get_length(); i++)
    {
        std::cout << (*arr4)[i] << " ";
    }
    std::cin.get();
}
