#include <iostream>
#include <vector>
#include <utility>		// For std::pair
#include <algorithm>  // For std::max and std::min
#include "PmergeMe.hpp"

extern int comparisonCount;

void PmergeMe::mergeInsertA(std::list<int>& input)
{
	input.sort();
}
void PmergeMe::mergeInsertB(std::deque<int>& input)
{
	// std::sort(input.begin(), input.end());
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
	return size;
}

// void PmergeMe::cheapSort(std::deque<int>& input)
// {
// 	int size = input.size();
// 	if (size == 1)
// 		return ;

// 	// Putting neighbors in one of the two arrays
// 	std::deque<int> smaller;
// 	std::deque<int> bigger;
// 	int max;
// 	int min;
// 	int i = 0;
// 	while (i + 1 < size)
// 	{
// 		compare(input[i], input[i + 1], &max, &min);
// 		bigger.push_back(max);
// 		smaller.push_back(min);
// 		i += 2;
// 	}
// 	if (i == size - 1)
// 		smaller.push_back(input[i]);

// 	// Sorting bigger elements
// 	cheapSort(bigger);

// 	// Putting bigger elements in input array
// 	input.clear();
// 	input.insert(input.end(), bigger.begin(), bigger.end());
	
// 	// Insert smaller elements
// 	for (auto it = smaller.begin(); it != smaller.end(); ++it)
// 		binaryInsert(input, *it, 0, input.size());
// }
// first is value. second is partner
// be careful with doubles for now
void PmergeMe::cheapSort(std::deque<int>& input)
{
	int size = input.size();
	if (size == 1)
		return ;

	// Putting neighbors in one of the two arrays
	std::deque<int> bigGroup;
	std::deque<tSmall> smallGroup;
	int bigNeighbor;
	int smallNeighbor;
	int i = 0;
	while (i + 1 < size)
	{
		compare(input[i], input[i + 1], &bigNeighbor, &smallNeighbor);
		bigGroup.push_back(bigNeighbor);
		smallGroup.emplace_back(smallNeighbor, bigNeighbor);
		i += 2;
	}
	if (i == size - 1)
		smallGroup.emplace_back(input[i], -1);

	// Sorting bigger elements
	cheapSort(bigGroup);

	// Applying order of bigger elements to smaller elements
	std::deque<tSmall> smallGroupOrdered;
	for (unsigned long i = 0; i < bigGroup.size(); ++i)
	{
		int value = bigGroup[i];
		for (unsigned long j = 0; j < smallGroup.size(); ++j)
		{
			if (value != smallGroup[j].bigNeighborVal)
				continue ;
			smallGroupOrdered.push_back(smallGroup[j]);
		}
	}
	if (smallGroup.size() % 2 == 1)
		smallGroupOrdered.push_back(smallGroup.back());
	for (unsigned long j = 0; j < smallGroup.size(); ++j)
	{
		std::cout << "Value: " << smallGroup[j].value << ", bigNeighborVal: " << smallGroup[j].bigNeighborVal << "\n";
	}

	// Putting bigger elements in input array
	input.clear();
	input.insert(input.end(), bigGroup.begin(), bigGroup.end());
	
	// Insert smaller elements
	// for (auto it = smallGroup.begin(); it != smallGroup.end(); ++it)
	// 	binaryInsert(input, it->value, 0, it->bigNeighborPos);
	std::vector<int> order = {0,2,1,4,3,10,9,8,7,6,5};
	int currentPos;
	for (int i = 0; i < bigGroup.size(); ++i)
	{
		currentPos = order[i];
		binaryInsert(bigGroup, smallGroupOrdered[currentPos].value, 0, getIndex(bigGroup, smallGroupOrdered[i].bigNeighborVal));
	}
	if (size % 2 == 1)
		binaryInsert(bigGroup, smallGroupOrdered.back(), 0, bigGroup.size())
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

