#include <iostream>
#include "custom_array.hpp"

int binary_search(Array *arr, int num)
{
    int begin = 0;
    int end = arr->length;
    int mid;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        
        if (arr->array[mid] == num)
        {
            return mid;
        }
        else if (arr->array[mid] < num)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    Array arr = {{1, 2, 5, 7, 9, 10, 12, 15, 20, 21, 22, 23}, 50, 11};

    std::cout << binary_search(&arr, 25) << std::endl;
}