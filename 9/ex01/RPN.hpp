#pragma once
#include <stack>
#include <string>
#include <cstring>
#include <stdexcept>
#include <climits>

class RPN
{
	private:
		RPN();
	public:
		static int calculate(char* str);
};