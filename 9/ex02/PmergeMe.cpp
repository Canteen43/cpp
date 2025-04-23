#include <iostream>
#include <vector>
#include <utility>		// For std::pair
#include <algorithm>  // For std::max and std::min
#include "PmergeMe.hpp"

extern int comparisonCount;
extern std::vector<int> order;

void PmergeMe::mergeInsertA(std::list<int>& input)
{
	input.sort();
}
void PmergeMe::mergeInsertB(std::deque<int>& input)
{
	cheapSort(input);
}


void compare(int first, int second, int* max, int* min)
{
	if (first > second)
	{
		*max = first;
		*min = second;
	}
	else
	{
		*max = second;
		*min = first;
	}
	comparisonCount++;
}
int getIndex(std::deque<int> container, int value)
{
	int size = container.size();
	for(int i = 0; i < size; ++i)
		if (container[i] == value)
			return i;
	throw std::runtime_error("Sorting failed because neighbor was lost");
}
void PmergeMe::binaryInsert(std::deque<int>& container, int value, int lowEnd, int highEnd)
{
	int mid;
	while (lowEnd != highEnd)
	{
		mid = (lowEnd + highEnd) / 2;
		if (value > container[mid])
			lowEnd = mid + 1;
		else
			highEnd = mid;
		comparisonCount++;
	}
	container.insert(container.begin() + lowEnd, value);
}


void PmergeMe::cheapSort(std::deque<int>& input)
{
	// Directly returning if size equals 1 to break recursive loop
	// (Declaring size as variable to avoid repeated calls)
	int inputSize = input.size();
	if (inputSize == 1)
		return ;

	// Putting neighbors in one of the two arrays
	std::deque<int> bigGroup;
	std::deque<tSmall> smallGroup;
	{
		int bigNeighbor;
		int smallNeighbor;
		for (int i = 0; i + 1 < inputSize; i += 2)
		{
			compare(input[i], input[i + 1], &bigNeighbor, &smallNeighbor);
			bigGroup.push_back(bigNeighbor);
			smallGroup.emplace_back(smallNeighbor, bigNeighbor);
		}
	}

	// Handling unpaired value for odd arrays
	int unpairedValue = -1;
	if (inputSize % 2 == 1)
		unpairedValue = input.back();

	// Sorting the bigger neighbors recursively
	cheapSort(bigGroup);

	// Putting bigger elements back into original input array
	input.clear();
	input.insert(input.end(), bigGroup.begin(), bigGroup.end());

	// Applying order of bigger elements to smaller elements
	std::deque<tSmall> smallGroupOrdered;
	smallGroupOrdered.resize(inputSize / 2);
	for (int i = 0; i < inputSize / 2; ++i)
	{
		int new_index = getIndex(bigGroup, smallGroup[i].bigNeighborVal);
		smallGroupOrdered[new_index] = smallGroup[i];
	}
	
	// Insert smaller elements
	{
	int i = 0;
	for (int inserted = 0; inserted < inputSize / 2; ++inserted)
	{
		while (order[i] >= inputSize / 2)
			++i;
		int currentPos = order[i];
		binaryInsert(input, smallGroupOrdered[currentPos].value, 0, getIndex(input, smallGroupOrdered[currentPos].bigNeighborVal));
		++i;
	}
	}

	// Inserting leftover unpaired value
	if (inputSize % 2 == 1)
		binaryInsert(input, unpairedValue, 0, inputSize - 1);
}
