#include "easyfind.hpp"
#include <iostream>
// Sequence containers:
#include <vector>
#include <deque>
#include <list>
// Associative containers:
#include <set>
#include <map> 
// Container adapters:
#include <stack>
#include <queue>


// What do I need to handle?
	// Sequence containers: vector, deque and list
// What don't I need to handle?
	// Associative containers: set, multiset, map, multimap
		// (Technically, they would work with my code)
	// Container adaptors: stack, queue, priority_queue
		// They are not explicitly ruled out by the subject.
		// However, they don't support iteration or the find() function.


template <typename cherry>
void fillArray(cherry& container)
{
	for (int i = 0; i < 10; ++i)
		container.push_back(i);
};

template <typename cherry>
void testEasyfind(cherry& container)
{
	std::cout << "Value inside container: ";
	if (container.end() == easyfind(container, 5))
		std::cout << "Value not found\n";
	else
		std::cout << "Value found\n";

	std::cout << "Value outside container: ";
	if (container.end() == easyfind(container, 15))
		std::cout << "Value not found\n\n";
	else
		std::cout << "Value found\n\n";
};


int main( void )
{
	std::cout << "\033[4mVector\033[0m\n";
	std::vector<int> Victor;
	fillArray(Victor);
	testEasyfind(Victor);

	std::cout << "\033[4mDeque\033[0m\n";
	std::deque<int> Decklin;
	fillArray(Decklin);
	testEasyfind(Decklin);

	std::cout << "\033[4mList\033[0m\n";
	std::list<int> Lisa;
	fillArray(Lisa);
	testEasyfind(Lisa);

	std::cout << "\033[4mSet\033[0m\n";
	std::set<int> Seth;
	for (int i = 0; i < 10; ++i)
		Seth.insert(i);
	testEasyfind(Seth);

	// std::cout << "\033[4mStefan\033[0m\n";
	// std::stack<int> Stefan;
	// for (int i = 0; i < 10; ++i)
	// 	Stefan.push(i);
	// testEasyfind(Stefan);
}
