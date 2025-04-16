#include "PmergeMe.hpp"
void PmergeMe::mergeInsertA(std::list<int> input)
{
	input.sort();
}
void PmergeMe::mergeInsertB(std::deque<int> input)
{
	// std::sort(input.begin(), input.end());
	cheapSort(input);
}

void PmergeMe::cheapSort(std::deque<int>& input)
{
	if (input.size() == 1)
		return ;

	// Putting smaller neighbors in temporary array
	std::deque<int> temp;
	auto next = input.end();
	next--;
	while (next != input.begin() && next != (input.begin() - 1))
	{
		auto A = next;
		auto B = A - 1;
		next -= 2;
		if (*A < *B)
		{
			temp.push_back(*A);
			input.erase(A);
		}
		else
		{
			temp.push_back(*B);
			input.erase(B);
		}
	}
	if (input.size() == 1)
	{
		temp.push_back(*input.begin());
		input.erase(input.begin());
	}

	// Sorting bigger elements
	cheapSort(input);
	
	// Insert smaller elements
	for (auto it = temp.begin(); it != temp.end(); ++it)
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
		++it;
	}
	container.insert(it, value);
}