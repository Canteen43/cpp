#pragma once
#include <stack>

class RPN
{
	private:
		std::stack<int> container;
	public:
		int calculate(std::string);
}