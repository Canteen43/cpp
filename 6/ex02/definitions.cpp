#include "header.hpp"

// Virtual destructor
Base::~Base()
{};

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * generate(void)
{
	switch (std::time(0) % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
};
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
};
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (const std::exception& e)
	{}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (const std::exception& e)
	{}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (const std::exception& e)
	{}
};