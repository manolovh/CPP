#include <iostream>
#include "CustomArray.hpp"

void delete_elem(ArrayStruct& arr, int idx)
{
    for (int i = idx; i < arr.length; i++)
    {
        arr.array[i] = arr.array[i + 1];
    }
    arr.length--;
}
