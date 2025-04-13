#include "PmergeMe.hpp"
void PmergeMe::mergeInsertA(std::list<int> input)
{
	input.sort();
}
void PmergeMe::mergeInsertB(std::deque<int> input)
{
	std::sort(input.begin(), input.end());
}