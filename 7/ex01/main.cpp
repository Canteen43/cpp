#include "iter.hpp"
#include <iostream>
#include <string>

void increase(double *nbr)
{
	*nbr += 1;
};

void printNbr(double *nbr)
{
	std::cout << *nbr << "\n";
};

void printStr(std::string *str)
{
	std::cout << *str << "\n";
};

int main( void )
{
	double doubleArr[] = {0.5,1.4,2.3,3.2,4.1,5.0};
	iter(doubleArr, 6, increase);
	iter(doubleArr, 6, printNbr);
	std::cout << "\n\n";
	std::string strArr[] = {"Luke", "I", "am", "your", "father"};
	iter(strArr, 5, printStr);
}