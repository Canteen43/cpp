#pragma once
#include <algorithm> // for std::sort
#include <deque>
#include <list>

struct smallNeighbor {
	int value;
	int bigNeighborVal;
	smallNeighbor(int sv, int bv) : value(sv), bigNeighborVal(bv) {}
	smallNeighbor() : value(-1), bigNeighborVal(-1) {}
};

typedef struct smallNeighbor tSmall;

class PmergeMe
{
	private:
		PmergeMe();
		static void cheapSort(std::deque<int>& input);
		static void lazyInsert(std::deque<int>& container, int value);
		static void binaryInsert(std::deque<int>& container, int value, int lowEnd, int highEnd);
		static void compare(int first, int second, int* max, int* min);
		static int getIndex(std::deque<int> container, int value);
	public:
		static void mergeInsertList(std::list<int>& input);
		static void mergeInsertDeque(std::deque<int>& input);
};