#include <iostream>
#include "CustomArray.hpp"

Array::Array(int *arr, size_t size, size_t length)
    : m_array{ arr }, size{ size }, length{ length } { }

int Array::get(int idx)
{
    if (idx >= 0 && idx < length) {
        return m_array[idx];
    }
    return -1;
}

void Array::set(int idx, int value)
{
    if (idx >= 0 && idx < length) {
        m_array[idx] = value;
    }
}

double Array::avg()
{
    double total = 0;

    for (int i = 0; i < length; i++)
    {
        total += m_array[i];
    }
    return total / length;
}

int Array::sum()
{
    double total = 0;

    for (int i = 0; i < length; i++)
    {
        total += m_array[i];
    }
    return total;
}

int Array::max()
{
    int max = 0;

    for (int i = 0; i < length; i++)
    {
        if (m_array[i] > max) {
            max = m_array[i];
        }
    }
    return max;
}

int Array::min()
{
    int min = m_array[0];

    for (int i = 0; i < length; i++)
    {
        if (m_array[i] < min) {
            min = m_array[i];
        }
    }
    return min;
}

void Array::reverse()
{
    int tmp;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        tmp = m_array[i];
        m_array[i] = m_array[j];
        m_array[j] = tmp;
    }
}

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}

void Array::insert(int idx)
{
    if (idx > -1 && idx < length)
    {
        int i = length - 1;
        while (m_array[i] > m_array[idx])
        {
            m_array[i + 1] = m_array[i];
            i--;
        }
        m_array[i + 1] = idx;
        length++;
    }
}

void Array::remove(int idx)
{
    if (idx > -1 && idx < length)
    {
        for (int i = idx; i < length; i++)
        {
            m_array[i] = m_array[i + 1];
        }
        length--;
    }
}

bool Array::is_sorted()
{
    for (int i = 1; i < length; i++)
    {
        if (m_array[i] < m_array[i - 1]) {
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
        while (m_array[i] < 0) {
            i++;
        }
        while (m_array[j] >= 0) {
            j--;
        }
        if (i < j)
        {
            tmp = m_array[i];
            m_array[i] = m_array[j];
            m_array[j] = tmp;
        }
    }
}

int& Array::operator[](int idx)
{
    return m_array[idx];
}

int Array::get_length()
{
    return length;
}