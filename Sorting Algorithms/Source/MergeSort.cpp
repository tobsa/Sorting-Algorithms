////////////////////////////////////////////////////////////////////////////////
// MergeSort.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "MergeSort.hpp"

////////////////////////////////////////////////////////////////////////////////
// Merge two vectors into the first
////////////////////////////////////////////////////////////////////////////////
static void merge(std::vector<int>& v, std::vector<int>& v1, std::vector<int>& v2)
{
	std::size_t i = 0;
	std::size_t j = 0;
	std::size_t k = 0;

	// Add the smallest value first to the new vector
	while(i < v1.size() && j < v2.size())
	{
		if(v1[i] <= v2[j])
			v[k] = v1[i++];
		else 
			v[k] = v2[j++];
		++k;
	}

	if(i == v1.size())
		std::copy(v2.begin() + j, v2.end(), v.begin() + k);
	else
		std::copy(v1.begin() + i, v1.end(), v.begin() + k);
}

////////////////////////////////////////////////////////////////////////////////
void mergeSort(std::vector<int>& v)
{
	if(v.size() > 1)
	{
		std::size_t size = v.size() / 2;
		std::vector<int> v1;
		std::vector<int> v2;

		// Copy the first half of the vector into one and the second half into the other one
		if(v.size() % 2 == 0)
		{
			v1.resize(size);
			v2.resize(size);
			std::copy(v.begin(), v.begin() + size, v1.begin());
			std::copy(v.begin() + size, v.end(), v2.begin());
		}
		else
		{
			v1.resize(size + 1);
			v2.resize(size);
			std::copy(v.begin(), v.begin() + size + 1, v1.begin());
			std::copy(v.begin() + size + 1, v.end(), v2.begin());
		}

		// Recursivly sort the halves and merge them together
		mergeSort(v1);
		mergeSort(v2);
		merge(v, v1, v2);
	}
}