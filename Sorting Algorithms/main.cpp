////////////////////////////////////////////////////////////////////////////////
// main.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random>
#include <functional>
#include "Source/BasicSortingAlgorithms.hpp"
#include "Source/TreeSort.hpp"

////////////////////////////////////////////////////////////////////////////////
// Print a vector
////////////////////////////////////////////////////////////////////////////////
void printVector(const std::vector<int>& v, bool newline = false);

////////////////////////////////////////////////////////////////////////////////
// Fill a vector with random numbers
////////////////////////////////////////////////////////////////////////////////
void fillVector(std::vector<int>& v, int size, int min, int max);

////////////////////////////////////////////////////////////////////////////////
// Verify if the vector is sorted
////////////////////////////////////////////////////////////////////////////////
bool verifySort(const std::vector<int>& v);

////////////////////////////////////////////////////////////////////////////////
// Sort a vector by a sorting function
////////////////////////////////////////////////////////////////////////////////
void handleSort(std::vector<int>& v, std::function<void(std::vector<int>&)> f, const std::string& name);

const int MaxVectorSize = 25;

////////////////////////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////////////////////////
int main()
{
	std::vector<int> v;

	bool quit = false;
	while(!quit)
	{
		// Choose algorithm
		std::cout << "Choose sorting algorithm: " << std::endl 
			      << " 1. Bubble Sort!"           << std::endl
			      << " 2. Selection Sort!"        << std::endl
			      << " 3. Insertion Sort!"        << std::endl
				  << " 4. Tree Sort!"             << std::endl
				  << " 5. Exit program!"          << std::endl 
				  << "Choice: ";
		char value;
		std::cin >> value;
		std::cout << std::endl;

		// Make sure the input is valid
		if(value < '1' || value > '5')
		{
			std::cout << "Not valid input!. Choose between 1-45." << std::endl << std::endl;
			continue;
		}
		else if(value == '5')
		{
			quit = true;
		}
		else
		{
			// Enter vector size, min and max value
			std::cout << "Enter vector size, min and max value ([size][min][max]): ";
			int size, min, max;
			std::cin >> size >> min >> max;

			fillVector(v, size, min, max);

			switch(value)
			{
				case '1': handleSort(v, bubbleSort,    "Bubble Sort");    break;
				case '2': handleSort(v, selectionSort, "Selection Sort"); break;
				case '3': handleSort(v, insertionSort, "Insertion Sort"); break;
				case '4': handleSort(v, treeSort,      "Tree Sort");      break;
			}
		}
	}

	std::cin.get();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
void printVector(const std::vector<int>& v, bool newline)
{
	if(newline)
	{
		for(std::size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
	}
	else
	{
		for(std::size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void fillVector(std::vector<int>& v, int size, int min, int max)
{
	// Make sure we have an empty vector
	v.clear();

	// Create a random number generator
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> distribution(min, max);

	auto generator = std::bind(distribution, engine);

	// Fill the vector with random numbers
	for(int i = 0; i < size; ++i)
		v.push_back(generator());
}

////////////////////////////////////////////////////////////////////////////////
bool verifySort(const std::vector<int>& v)
{
	// Check if the vector is sorted
	for(std::size_t i = 0; i < v.size() - 1; ++i)
	{
		// If the next element is smaller than the previous one then the vector is not sorted
		if(v[i] > v[i + 1])
			return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void handleSort(std::vector<int>& v, std::function<void(std::vector<int>&)> f, const std::string& name)
{
	std::cout << std::endl << "----- " << name << " (" << v.size() << ") -----" << std::endl;

	if(v.size() <= MaxVectorSize)
		printVector(v, false);

	f(v);

	if(v.size() <= MaxVectorSize)
		printVector(v, false);

	verifySort(v) ? std::cout << " Sorted!" : std::cout << " Unsorted!";
	std::cout << std::endl << std::endl;
}