#include <iostream>
#include "CustomArray.hpp"

Array::Array(int *arr, size_t size, size_t length)
    : m_array{ arr }, size{ size }, length{ length } { }

Array::Array(size_t size, size_t length)
    : size{ size }, length{ length }
{
    m_array = new int[size];
}

Array::~Array()
{
    delete m_array;
}

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

void Array::append(int num)
{
    if (length < size)
    {
        m_array[length] = num;
        length++;
    }
}

void Array::insert(int idx, int num)
{
    if (idx >= 0 && idx < length && length < size)
    {
        for (int i = length; i > idx; i--)
        {
            m_array[i] = m_array[i - 1];
        }
        m_array[idx] = num;
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

void Array::increase_length()
{
    length++;
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

/* Merge two arrays with equal size */
Array* Array::merge(Array* arr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int *new_arr = new int[length * 2];
	Array *merged_arr = new Array{ new_arr, length * 2, length * 2};

	while (k < length * 2)
	{
		if (i < length && m_array[i] < (*arr)[j]) {
			(*merged_arr)[k++] = m_array[i++];
		}
		else {
			if (j < arr->length) {
				(*merged_arr)[k++] = (*arr)[j++];
			}
		}
	}
	return merged_arr;
}

int& Array::operator[](int idx)
{
    return m_array[idx];
}

int Array::get_length()
{
    return length;
}

Array* Array::make_union(Array* arr)
{
    int k = 0;
    Array* new_union = new Array{ length + arr->get_length(), length + arr->get_length() };

    for (; k < length; k++)
    {
        (*new_union)[k] = m_array[k];
    }

    for (int i = 0; i < arr->get_length(); i++)
    {
        bool elem_in = false;
        for (int j = 0; j < length; j++)
        {
            if ((*arr)[i] == m_array[j]) {
                elem_in = true;
                break;
            }
        }
        if (!elem_in) {
            (*new_union)[k++] = (*arr)[i];
        }
    }
    return new_union;
}

Array* Array::get_intersection(Array* arr)
{
    Array* new_union = new Array{ length, 0 };

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < arr->get_length(); j++)
        {
            if ((m_array[i] == (*arr)[j]) && (new_union->linear_search_1(m_array[i]) == -1))
            {
                std::cout << "Entered if condition in loop..." << std::endl;
                new_union->append(m_array[i]);
                break;
            }
        }
    }
    return new_union;
}

Array* Array::get_difference(Array* arr)
{
    Array* new_union = new Array{ length, 0 };

    for (int i = 0; i < length; i++)
    {
        bool elem_in = false;
        for (int j = 0; j < arr->get_length(); j++)
        {
            if ((m_array[i] == (*arr)[j]) && (new_union->linear_search_1(m_array[i]) == -1))
            {
                elem_in = true;
                break;
            }
        }
        if (!elem_in) {
            new_union->append(m_array[i]);
        }
    }
    return new_union;
}
