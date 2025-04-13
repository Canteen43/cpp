#pragma once
#include <algorithm> // for std::sort
#include <deque>
#include <list>

class PmergeMe
{
	private:
		PmergeMe();
	public:
		static void mergeInsertA(std::list<int> input);
		static void mergeInsertB(std::deque<int> input);
};