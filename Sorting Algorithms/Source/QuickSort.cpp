////////////////////////////////////////////////////////////////////////////////
// QuickSort.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "QuickSort.hpp"

////////////////////////////////////////////////////////////////////////////////
// Sort the vector with the quick sort algorithm
////////////////////////////////////////////////////////////////////////////////
static void quickSort(std::vector<int>& v, int lhs, int rhs)
{
	// Select pivot point
	int pivot = v[(lhs + rhs) / 2];
	int i = lhs;
	int j = rhs;

	do
	{
		// Find the next two indices that should be swapped
		while(v[i] < pivot && i < rhs)
			++i;
		while(v[j] > pivot && j > lhs)
			--j;

		if(i <= j)
		{
			std::swap(v[i], v[j]),
			++i;
			--j;
		}

	}while(i <= j);

	// Recursivly sort the two halves
	if(lhs < j)
		quickSort(v, lhs, j);
	if(i < rhs)
		quickSort(v, i, rhs);

}

////////////////////////////////////////////////////////////////////////////////
void quickSort(std::vector<int>& v)
{
	quickSort(v, 0, v.size() - 1);
}