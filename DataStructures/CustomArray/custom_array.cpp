#include <iostream>
#include "CustomArray.hpp"

Array::Array(int array[50], size_t size, size_t length)
    : array{array}, size{size}, length{length} { }

int Array::get(int idx)
{
    if (idx >= 0 && idx < length) {
        return array[idx];
    }
    return -1;
}

void Array::set(int idx, int value)
{
    if (idx >= 0 && idx < length) {
        array[idx] = value;
    }
}

double Array::avg()
{
    double total = 0;

    for (int i = 0; i < length; i++)
    {
        total += array[i];
    }
    return total / length;
}

int Array::sum()
{
    double total = 0;

    for (int i = 0; i < length; i++)
    {
        total += array[i];
    }
    return total;
}

int Array::max()
{
    int max = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int Array::min()
{
    int min = array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void Array::reverse()
{
    int tmp;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Array::insert(int x)
{
    if (size > length)
    {
        int i = length - 1;
        while (array[i] > x)
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = x;
        length++;
    }
}

bool Array::is_sorted()
{
    for (int i = 1; i < length; i++)
    {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

/* Make sure all negative elements are placed before the positive ones.*/
void Array::rearrange()
{
    int i = 0;
    int j = length - 1;
    int tmp;

    while (i < j)
    {
        while (array[i] < 0) {
            i++;
        }
        while (array[j] >= 0) {
            j--;
        }
        if (i < j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
}