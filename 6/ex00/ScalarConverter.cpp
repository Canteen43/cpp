#include "ScalarConverter.hpp"

bool isChar(char *input)
{
	if (*(input + 1) != '\0')
		return false;
	if (*input < 33 || *input > 127)
		return false;
	if (*input >= '0' && *input <= '9')
		return false;
	return true;
};

bool isInt(char *input)
{
	long nbr = 0;
	int i = 0;
	int factor = 1;

	if (input[i] == '-')
	{
		factor = -1;
		++i;
	}
	while (input[i])
	{
		if (!isdigit(input[i]))
			return false;
		nbr = nbr * 10 + (input[i] - '0') * factor;
		if (nbr > INT_MAX || nbr < INT_MIN)
			return false;
		++i;
	}
	return true;
}

bool isFloat(char *input)
{
	std::string str(input);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;

	int i = 0;
	if (input[i] == '-')
		++i;
	if (!isdigit(input[i]))
		return false;
	while (isdigit(input[i]))
		++i;
	if (input[i] != '.')
		return false;
	++i;
	if (!isdigit(input[i]))
		return false;
	while (isdigit(input[i]))
		++i;
	if (input[i] != 'f')
		return false;
	i++;
	if (input[i] != '\0')
		return false;
	return true;
}

bool isDouble(char *input)
{
	std::string str(input);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

	int i = 0;
	if (input[i] == '-')
		++i;
	if (!isdigit(input[i]))
		return false;
	while (isdigit(input[i]))
		++i;
	if (input[i] != '.')
		return false;
	++i;
	if (!isdigit(input[i]))
		return false;
	while (isdigit(input[i]))
		++i;
	if (input[i] != '\0')
		return false;
	return true;
}

void convertChar(char *input)
{
	// Char conversion
	std::cout << "char: '" << *input << "'\n";
	// Int conversion
	std::cout << "int: " << static_cast<int>(*input) << "\n";
	// Float conversion
	std::cout << "float: " << static_cast<float>(*input) << "f\n";
	// Double conversion
	std::cout << "double: " << static_cast<double>(*input) << "\n";
}

void convertInt(char *input)
{
	// Extracting int
	long longNbr = 0;
	int nbr;
	int i = 0;
	int factor = 1;
	if (input[i] == '-')
	{
		factor = -1;
		++i;
	}
	while (input[i])
	{
		longNbr = longNbr * 10 + (input[i] - '0') * factor;
		++i;
	}
	nbr = longNbr;

	// Char conversion
	if (nbr < 0 || nbr > 128)
		std::cout << "char: impossible\n";
	else if (nbr < 33 || nbr > 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'\n";

	// Int conversion
	std::cout << "int: " << nbr << "\n";

	// Float conversion
	std::cout << "float: " << static_cast<float>(nbr) << "f\n";
	// Double conversion
	std::cout << "double: " << static_cast<double>(nbr) << "\n";
}

void convertFloat(char *input)
{
	float nbr = 0;
	// Extracting special floats
	std::string str(input);
	if (str == "-inff")
		nbr = -INFINITY;
	if (str == "+inff")
		nbr = INFINITY;
	if (str == "nanf")
		nbr = NAN;
	
	// Extracting float
	if ( nbr == 0)
	{
	int i = 0;
	int factor = 1;
	if (input[i] == '-')
	{
		factor = -1;
		++i;
	}
	while (isdigit(input[i]))
	{
		nbr = nbr * 10 + (input[i] - '0') * factor;
		++i;
	}
	int decimalPos = i;
	++i;
	while (isdigit(input[i]))
	{
		nbr += factor * (input[i] - '0') / pow(10, i - decimalPos);
		++i;
	}
	}

	// Char conversion
	if (nbr < 0 || nbr > 128 || nbr == INFINITY || nbr == -INFINITY || std::isnan(nbr))
		std::cout << "char: impossible\n";
	else if (nbr < 33 || nbr > 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'\n";

	// Int conversion
	if (nbr > (float)INT_MAX || nbr < (float)INT_MIN || std::isnan(nbr))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(nbr) << "\n";

	// Float conversion
	std::cout << "float: " << nbr << "f\n";
	
	// Double conversion
	std::cout << "double: " << static_cast<double>(nbr) << "\n";
}

void convertDouble(char *input)
{
	double nbr = 0;
	// Extracting special doubles
	std::string str(input);
	if (str == "-inf")
		nbr = -INFINITY;
	if (str == "+inf")
		nbr = INFINITY;
	if (str == "nan")
		nbr = NAN;
	
	// Extracting double
	if (nbr == 0)
	{
	int i = 0;
	int factor = 1;
	if (input[i] == '-')
	{
		factor = -1;
		++i;
	}
	while (isdigit(input[i]))
	{
		nbr = nbr * 10 + (input[i] - '0') * factor;
		++i;
	}
	int decimalPos = i;
	++i;
	while (isdigit(input[i]))
	{
		nbr += factor * (input[i] - '0') / pow(10, i - decimalPos);
		++i;
	}
	}

	// Char conversion
	if (nbr < 0 || nbr > 128 || nbr == INFINITY || nbr == -INFINITY || std::isnan(nbr))
		std::cout << "char: impossible\n";
	else if (nbr < 33 || nbr > 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'\n";

	// Int conversion
	if (nbr > (double)INT_MAX || nbr < (double)INT_MIN || std::isnan(nbr))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(nbr) << "\n";

	// Float conversion
	std::cout << "float: " << static_cast<float>(nbr) << "f\n";
	
	// Double conversion
	std::cout << "double: " << nbr << "\n";
}

void ScalarConverter::convert(char *input)
{
	// Making sure that float and double always print exactly one digit after the decimal point
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	
	else
		std::cout << "Invalid input\n";
}