#include <iostream>
#include "CustomArray.hpp"

Array* Array::merge(Array* arr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array merged_arr = { {0}, length * 2, length * 2 };

	while (k < length * 2)
	{
		if (i < length && arr[i] < arr[j]) {
			merged_arr->array[k++] = arr[i++];
		}
		else if (j < arr->length() && arr[j] <= arr[i]) {
			merged_arr->array[k++] = arr[j++];
		}
	}
	
	return &merged_arr;
}