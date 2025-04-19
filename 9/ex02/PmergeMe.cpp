#include <iostream>
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

void PmergeMe::cheapSort(std::deque<int>& input)
{
	int size = input.size();
	if (size == 1)
		return ;

	// Putting neighbors in one of the two arrays
	std::deque<int> smaller;
	std::deque<int> bigger;
	int max;
	int min;
	int i = 0;
	while (i + 1 < size)
	{
		compare(input[i], input[i + 1], &max, &min);
		bigger.push_back(max);
		smaller.push_back(min);
		i += 2;
	}
	if (i == size - 1)
		smaller.push_back(input[i]);

	// Sorting bigger elements
	cheapSort(bigger);

	// Putting bigger elements in input array
	input.clear();
	input.insert(input.end(), bigger.begin(), bigger.end());
	
	// Insert smaller elements
	for (auto it = smaller.begin(); it != smaller.end(); ++it)
		lazyInsert(input, *it);
}

void PmergeMe::lazyInsert(std::deque<int>& container, int value)
{
	auto it = container.begin();
	while (it != container.end())
	{
		if (*it > value)
		{
			container.insert(it, value);
			return ;
		}
		comparisonCount++;
		++it;
	}
	container.insert(it, value);
}