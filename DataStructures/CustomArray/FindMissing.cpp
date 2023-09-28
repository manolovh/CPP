#include <iostream>
#include "CustomArray.hpp"

void Array::find_missing()
{
	int difference = m_array[0];
	for (int i = 1; i < length; i++)
	{
		if (m_array[i] - i != difference)
		{
			while (difference < m_array[i] - i)
			{
				std::cout << "Missing " << difference + i << std::endl;
				difference++;
			}
		}
	}
}

void Array::find_missing_unsorted()
{
	// Make array with one more element and max value
	int low = 1, high = 12;
	int elements[high + 1] = { 0 };

	for (int i = 0; i < length; i++)
	{
		elements[m_array[i]] = 1;
	}

	for (int i = low; i < high + 1; i++)
	{
		if (elements[i] == 0) {
			std::cout << "Missing " << i << std::endl;
		}
	}
}

void Array::find_duplicates()
{
	int min_elem = 1, max_elem = 8;
	int has_duplicates[max_elem + 1] = { 0 };
	for (int i = 0; i < length; i++)
	{
		has_duplicates[m_array[i]] += 1;
	}

	for (int i = min_elem; i < max_elem; i++)
	{
		if (has_duplicates[i] > 1)
		{
			std::cout << i << " has duplicates. Exactly " << has_duplicates[i] << std::endl;
		}
	}
}
