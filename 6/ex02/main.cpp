#include "header.hpp"
int main()
{
	Base* test = generate();
	identify(test);
	identify(*test);
	return 0;
}