////////////////////////////////////////////////////////////////////////////////
// HeapSort.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "HeapSort.hpp"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Bubble up the value troughout the heap
////////////////////////////////////////////////////////////////////////////////
static void bubbleUp(std::vector<int>& heap, int current)
{
	// Get the parent index
	int parent = (current - 1) / 2;

	// If they are in correct order then simply return
	if(heap[current] <= heap[parent])
		return;

	std::swap(heap[current], heap[parent]);

    bubbleUp(heap, parent);
}

////////////////////////////////////////////////////////////////////////////////
// Bubble down the value troughout the heap
////////////////////////////////////////////////////////////////////////////////
static void bubbleDown(std::vector<int>& heap, int current)
{
	// Get the child index
    int child = 2 * current + 1;

    if(child >= static_cast<int>(heap.size()))
        return;

    if(child + 1 < static_cast<int>(heap.size()))
    {
        if(heap[child] < heap[child + 1])
            child++;
    }

    if(heap[current] < heap[child])
		std::swap(heap[current], heap[child]);

    bubbleDown(heap, child);
}

////////////////////////////////////////////////////////////////////////////////
void heapSort(std::vector<int>& v)
{
	std::vector<int> heap;	

	// Constuct the heap
	for(std::size_t i = 0; i < v.size(); ++i)
	{
		heap.push_back(v[i]);
		bubbleUp(heap, heap.size() - 1);
	}

	v.clear();

	// Remove items from the heap and add them to the vector
	while(!heap.empty())
	{
		v.push_back(heap[0]);
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		bubbleDown(heap, 0);
	}

	// Since the vector now contains all the element in wrong order we need to reverse 
	// the vector
	std::reverse(v.begin(), v.end());
}