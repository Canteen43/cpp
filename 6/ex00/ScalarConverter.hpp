#pragma once
#include <iostream>
#include <cctype>	//for isdigit()
#include <climits>	//for INT_MAX and INT_MIN
#include <math.h>	//for pow()


class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void convert(char *input);
};
bool isChar(char *input);
bool isInt(char *input);
bool isFloat(char *input);
bool isDouble(char *input);
void convertChar(char *input);
void convertInt(char *input);
void convertFloat(char *input);
void convertDouble(char *input);