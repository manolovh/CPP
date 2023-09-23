#include <iostream>
#include "CustomArray.hpp"

Array* Array::merge(Array* arr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array* merged_arr = new Array{ {0}, length * 2, length * 2 };

	while (k < length * 2)
	{
		if (i < length && m_array[i] < (*arr)[j]) {
			(*merged_arr)[k++] = m_array[i++];
		}
		else if (j < arr->length && (*arr)[j] <= m_array[i]) {
			(*merged_arr)[k++] = (*arr)[j++];
		}
	}
	
	
	return merged_arr;
}