#include <iostream>
#include "custom_array.hpp"

int get(Array *arr, int idx)
{
    return arr->array[idx];
}

void set(Array *arr, int idx, int value)
{
    arr->array[idx] = value;
}

double avg(Array *arr)
{
    double total = 0;

    for (int i = 0; i < arr->length; i++)
    {
        total += arr->array[i];
    }
    return total / arr->length;
}

int max(Array *arr)
{
    int max = 0;

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->array[i] > max) {
            max = arr->array[i];
        }
    }
    return max;
}

int main()
{
    Array arr = {{1, 2, 3, 4, 5}, 50, 5};

    std::cout << get(&arr, 2) << std::endl;
    set(&arr, 2, 2);
    std::cout << get(&arr, 2) << std::endl;
    std::cout << avg(&arr) << std::endl;
    std::cout << max(&arr) << std::endl;
}