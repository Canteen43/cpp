#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include "Span.hpp"
int main()
{
	std::cout << "\033[4mSubject tests:\033[0m\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n\033[4mMy own tests:\033[0m\n";
	std::cout << "Can I construct non-parametrically?\n";
	Span A;
	try
	{
		A.addNumber(15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Can I copy the previous span?\n";
	Span B = sp;
	std::cout << B.shortestSpan() << std::endl;
	std::cout << B.longestSpan() << std::endl;
	std::cout << "Can I really copy the previous span?\n";
	Span C(sp);
	std::cout << C.shortestSpan() << std::endl;
	std::cout << C.longestSpan() << std::endl;
	std::cout << "Can I handle batshit crazy large spans?\n";
	std::srand(std::time(0));
	int hugeSize = 50000;
	Span D(hugeSize);
	std::vector<int> Vicky;
	for (int i = 0; i < hugeSize; ++i)
	{
		Vicky.push_back(std::rand());
	}
	D.addRange(hugeSize, Vicky.begin(), Vicky.end());
	std::cout << D.shortestSpan() << std::endl;
	std::cout << D.longestSpan() << std::endl;
	std::cout << "What if the range is too large?\n";
	Span E(hugeSize - 1);
	try
	{
		D.addRange(hugeSize, Vicky.begin(), Vicky.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "What if I call shortest or longest Span on empty spans?\n";
	try
	{
		std::cout << E.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << E.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}