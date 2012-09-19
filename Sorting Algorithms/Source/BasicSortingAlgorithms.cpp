////////////////////////////////////////////////////////////////////////////////
// BasicSortingAlgorithms.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "BasicSortingAlgorithms.hpp"

////////////////////////////////////////////////////////////////////////////////
void bubbleSort(std::vector<int>& v)
{
	for(std::size_t i = 0; i < v.size() - 1; ++i)
	{
		for(std::size_t j = 0; j < v.size() - 1 - i; ++j)
		{
			// If the elements are in wrong order then swap them
			if(v[j + 1] < v[j])
				std::swap(v[j],v[j + 1]);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
void selectionSort(std::vector<int>& v)
{
	for(std::size_t i = 0; i < v.size() - 1; ++i)
	{
		std::size_t min = i; // Current index with smallest value
		for(std::size_t j = i + 1; j < v.size(); ++j)
		{
			// If a smaller element was found than the element in the current index, then mark it as the smallest
			if(v[j] < v[min])
				min = j;
		}

		std::swap(v[i], v[min]);
	}
}

////////////////////////////////////////////////////////////////////////////////
void insertionSort(std::vector<int>& v)
{
	for(std::size_t i = 1; i < v.size(); ++i)
	{
		int value = v[i];
		int j = i - 1;

		// Move down smaller values
		while(j >= 0 && v[j] > value)
		{
			v[j + 1] = v[j];
			--j;
		}

		v[j + 1] = value;
	}
}