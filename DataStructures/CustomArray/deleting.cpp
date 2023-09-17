#include <iostream>
#include "custom_array.hpp"

void delete_elem(Array& arr, int idx)
{
    for (int i = idx; i < arr.length; i++)
    {
        arr.array[i] = arr.array[i + 1];
    }
    arr.length--;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 50, 5};

    delete_elem(arr, 3);

    for (int i = 0; i < arr.length; i++)
    {
        std::cout << arr.array[i] << std::endl;
    }
}