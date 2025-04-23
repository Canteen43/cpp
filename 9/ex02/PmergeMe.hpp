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

extern int comparisonCount;

class PmergeMe
{
	private:
		PmergeMe();
		static void compare(int first, int second, int* max, int* min);
		static int getIndex(std::deque<int> container, int value);
	public:
		static void mergeInsertVector(std::vector<int>& input);
		static void mergeInsertDeque(std::deque<int>& input);
	// template:
		template <typename Container>
		static void binaryInsert(Container& container, int value, int lowEnd, int highEnd)
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

};

