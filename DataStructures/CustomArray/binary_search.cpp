#include <iostream>
#include "CustomArray.hpp"

int binary_search(ArrayStruct *arr, int num)
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