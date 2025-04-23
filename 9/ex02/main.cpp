/*
Requirements:
	- Program that takes positive ints as args
		- they come as separate args. not in one string
	- Special sort
	- allow duplicates for now

Output:
	Before: 3 5 9 7 4
	After: 3 4 5 7 9
	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stdexcept>
#include <sstream>
#include <algorithm> // for std::sort
#include <ctime>  // For clock()
#include "PmergeMe.hpp"

template <typename Func, typename Arg>
double timedRun(Func f, Arg& a)
{
	std::clock_t start = std::clock();
	f(a);
	std::clock_t end = std::clock();
	return 1000000 * double(end - start) / CLOCKS_PER_SEC;
}

int comparisonCount = 0;

std::vector<int> order;

// Forbidden containers: std::map, std::stack
int main(int argc, char** argv)
{
	try
	{
		// Check argument count
		if (argc < 3)
			throw std::runtime_error("Program requires at least two arguments");

		// Fill container
		std::vector<int> mainContainer;
		for (int i = 1; i < argc; ++i)
		{
			int value;
			std::istringstream iss(argv[i]);
			iss >> std::noskipws >> value;
			if (!iss.eof())
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' contains non-digits");
			if (iss.fail())
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' is off limits");
			if (value < 0)
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' is smaller than zero");
			if (std::find(mainContainer.begin(), mainContainer.end(), value) != mainContainer.end())
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' is a duplicate");
			mainContainer.push_back(value);
		}

		// Create order of indexes to insert
		{
			int capacity = (argc - 1) / 2;
			order.resize(capacity);
			int group = 2;
			int groupNext = 2;
			int groupCount = 0;
			int lastStart = 0;
			int tmp;
			int number;
			for (int i = 1; i < capacity; ++i)
			{
				if (groupCount == group)
				{
					tmp = groupNext;
					groupNext = groupNext + 2 * group;
					group = tmp;
					groupCount = 0;
				}
				if (groupCount == 0)
				{
					number = lastStart + group;
					lastStart = number;
				}
				while (number >= capacity)
					--number;
				order[i] = number;
				++groupCount;
				--number;
			}
		}

		// Create sorted container
		std::vector<int> mainSorted(mainContainer);
		std::sort(mainSorted.begin(), mainSorted.end());

		// Other containers
		std::list<int> containerA(mainContainer.begin(), mainContainer.end());
		std::deque<int> containerB(mainContainer.begin(), mainContainer.end());
		double runTimeA = timedRun(PmergeMe::mergeInsertA, containerA);
		double runTimeB = timedRun(PmergeMe::mergeInsertB, containerB);

		// Print output
		std::cout << "B:";
		for (auto it = containerB.begin(); it != containerB.end(); ++it)
			std::cout << " " << *it;
		std::cout << "\n";

		// Check if sorting worked
		if (containerA.size() != mainSorted.size() 
		|| !std::equal(containerA.begin(), containerA.end(), mainSorted.begin()))
			throw std::runtime_error("Sorting of A was not successful.");
		if (containerB.size() != mainSorted.size() 
			|| !std::equal(containerB.begin(), containerB.end(), mainSorted.begin()))
			throw std::runtime_error("Sorting of B was not successful.");

		// Print output
		std::cout << "Before:";
		for (std::vector<int>::iterator it = mainContainer.begin(); it != mainContainer.end(); ++it)
			std::cout << " " << *it;
		std::cout << "\n";

		std::cout << "After:";
		for (std::vector<int>::iterator it = mainSorted.begin(); it != mainSorted.end(); ++it)
			std::cout << " " << *it;
		std::cout << "\n";

		std::cout << "Time to process a range of "
			<< mainContainer.size() 
			<< " elements with std::list : "
			<< runTimeA
			<< " microseconds\n";

		std::cout << "Time to process a range of "
			<< mainContainer.size() 
			<< " elements with std::deque : "
			<< runTimeB
			<< " microseconds\n";

		std::cout << "Number of comparisons: " << comparisonCount << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}