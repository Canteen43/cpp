#include "ScalarConverter.hpp"
void ScalarConverter::convert(char *input)
{
	char cValue = 42;
	int iValue = 42;
	float fValue = 42.0f;
	double dValue = 42.5;
	(void)input;
	std::cout << "char: '" << cValue << "'\n";
	std::cout << "int: " << iValue << "\n";
	std::cout << "float: " << fValue << "\n";
	std::cout << "double: " << dValue << "\n";
}