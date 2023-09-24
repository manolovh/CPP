#include <iostream>
#include "CustomArray.hpp"

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