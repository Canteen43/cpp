#include "iter.hpp"
#include <iostream>
#include <string>

void increase(double *nbr)
{
	*nbr += 1;
};

template <typename Banana>
void print(Banana *elem)
{
	std::cout << *elem << "\n";
}

int main( void )
{
	double doubleArr[] = {0.1, 0.2, 0.3};
	iter(doubleArr, 3, increase);
	iter(doubleArr, 3, print);
	std::cout << "\n";
	std::string strArr[] = {"Luke", "I", "am", "your", "father"};
	iter(strArr, 5, print);
}