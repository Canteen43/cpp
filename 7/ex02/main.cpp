#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Array.hpp"

#define MAX_VAL 750
int main(void)
{
	std::cout << "\033[4mMain from project page\033[0m\n";
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//


	std::cout << "\n\033[4mMy simple tests\033[0m\n";
	Array<std::string> foo;
	std::cout << "Size of empty array: " << foo.size() << "\n";
	Array<std::string> bar(4);
	std::cout << "Size of non-empty array: " << bar.size() << "\n";
	std::cout << "Default contents of array:\n";
	for (int i = 0; i < 4; ++i)
		std::cout << bar[i] << "\n";
	for (int i = 0; i < 4; ++i)
	{
		std::ostringstream oss;
		oss << i;
		bar[i] = oss.str();
	}
	std::cout << "Changed contents of non-empty array:\n";
	for (int i = 0; i < 4; ++i)
		std::cout << bar[i] << "\n";
	Array<std::string> copycat(bar);
	foo = bar;
	std::cout << "Does copying work?:\n";
	for (int i = 0; i < 4; ++i)
	{
		std::cout << foo[i] << "\n";
		std::cout << copycat[i] << "\n";
	}
	return 0;
}