#pragma once
#include <algorithm> // for std::sort
#include <deque>
#include <list>

class PmergeMe
{
	private:
		PmergeMe();
		static void cheapSort(std::deque<int>& input);
		static void lazyInsert(std::deque<int>& container, int value);
	public:
		static void mergeInsertA(std::list<int>& input);
		static void mergeInsertB(std::deque<int>& input);
};