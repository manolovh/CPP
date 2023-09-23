#include <iostream>
#include "CustomArray.hpp"

int Array::linear_search_1(int num)
{
    for (int i = 0; i < length; i++)
    {
        if (m_array[i] == num)
        {
            if (i > 0)
            {
                int tmp;

                // Push forward the element in order to be found easier next time 
                tmp = m_array[i - 1];
                m_array[i - 1] = m_array[i];
                m_array[i] = tmp;

                return i - 1;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}

int Array::linear_search_2(int num)
{
    for (int i = 0; i < length; i++)
    {
        if (m_array[i] == num)
        {
            if (i > 0)
            {
                int tmp;

                // Push to beginning the element in order to be found easier next time 
                tmp = m_array[0];
                m_array[0] = m_array[i];
                m_array[i] = tmp;

                return 0;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}
