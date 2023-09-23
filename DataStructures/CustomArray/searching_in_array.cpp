#include <iostream>
#include "CustomArray.hpp"

int linear_search_1(ArrayStruct *arr, int num)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->array[i] == num)
        {
            if (i > 0)
            {
                int tmp;

                // Push forward the element in order to be found easier next time 
                tmp = arr->array[i - 1];
                arr->array[i - 1] = arr->array[i];
                arr->array[i] = tmp;

                return i - 1;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}

int linear_search_2(ArrayStruct *arr, int num)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->array[i] == num)
        {
            if (i > 0)
            {
                int tmp;

                // Push to beginning the element in order to be found easier next time 
                tmp = arr->array[0];
                arr->array[0] = arr->array[i];
                arr->array[i] = tmp;

                return 0;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}
