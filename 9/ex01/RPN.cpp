#include "RPN.hpp"
#include <iostream>

int RPN::calculate(char* string)
{
	std::stack<int> container;
	bool spaceExpected = false;

	for (int i = 0; string[i]; ++i)
	{
		// Handle space
		if (spaceExpected && string[i] != ' ')
			throw std::runtime_error("No space");
		if (spaceExpected && string[i] == ' ')
		{
			spaceExpected = false;
			continue;
		}

		// Handle digits
		if (string[i] >= '0' && string[i] <= '9')
		{
			container.push(string[i] - '0');
			spaceExpected = true;
			continue;
		}

		// Handle operators
		if (!strchr("+-/*", string[i]))
			throw std::runtime_error("Wrong char");
		if (container.size() < 2)
			throw std::runtime_error("Too few operands");
		long int last = container.top();
		container.pop();
		long int result;
		switch (string[i])
		{
			case '+':
				result = container.top() + last;
				break;
			case '-':
				result = container.top() - last;
				break;
			case '*':
				result = container.top() * last;
				break;
			case '/':
				if (last == 0)
					throw std::runtime_error("Zero division");
				result = container.top() / last;
				break;
		}
		if (result < INT_MIN || result > INT_MAX)
			throw std::runtime_error("Out of bounds");
		container.top() = result;
		spaceExpected = true;
	}

	// Checking if all operands were used and only one item is left
	if (container.size() != 1)
		throw std::runtime_error("Too many operands");
	return container.top();
	
}