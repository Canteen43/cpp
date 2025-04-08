#pragma once
#include <stack>

class RPN
{
	private:
		std::stack<int>;
	public:
		int calculate(std::string);
}