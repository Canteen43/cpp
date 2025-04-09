#include "RPN.hpp"

int RPN::calculate(char* string)
{
	bool spaceExpected = false;

	for (int i = 0; string[i]; ++i)
	{
		// Handle space
		if (spaceExpected && string[i] != ' ')
			return -1;
		if (spaceExpected && string[i] == ' ')
		{
			spaceExpected = false;
			continue;
		}

		// Handle digits
		if (string[i] >=0 && string[i] <= 9)
		{
			container.push(string[i] - '0');
			spaceExpected = true;
			continue;
		}

		// Handle operators
		if (!strchr("+-/*", string[i]))
			return -1;
		if (container.size() < 2)
			return -1;
		int last = container.top()
	}
}