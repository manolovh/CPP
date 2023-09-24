#include <iostream>
#include "CustomArray.hpp"

int Array::binary_search(int num)
{
    int begin = 0;
    int end = length;
    int mid;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        
        if (m_array[mid] == num)
        {
            return mid;
        }
        else if (m_array[mid] < num)
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