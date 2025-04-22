#pragma once
#include <algorithm> // for std::sort
#include <deque>
#include <list>

struct smallNeighbor {
	int value;
	int bigNeighborVal;
	smallNeighbor(int sv, int bv) : value(sv), bigNeighborVal(bv) {}
};

typedef struct smallNeighbor tSmall;

class PmergeMe
{
	private:
		PmergeMe();
		static void cheapSort(std::deque<int>& input);
		static void lazyInsert(std::deque<int>& container, int value);
		static void binaryInsert(std::deque<int>& container, int value, int lowEnd, int highEnd);
	public:
		static void mergeInsertA(std::list<int>& input);
		static void mergeInsertB(std::deque<int>& input);
};