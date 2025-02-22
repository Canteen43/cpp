#include "Fixed.hpp"
#include <iostream>
#include <cmath>
// •A static constant integer to store the number of fractional bits. Its value
// will always be the integer literal 8.
const int Fixed::fbits = 8;

// •A default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}
// •A copy constructor.
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	value = other.value;
}
// •A copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	value = other.value;
	return *this;
}
// •A destructor.
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
// •A member function int getRawBits( void ) const;
// that returns the raw value of the fixed-point value.
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return value;
}
// •A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw )
{
	value = raw;
}
// •A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
Fixed::Fixed(const int set_value)
{
	std::cout << "Int constructor called\n";
	value = set_value << fbits;
}
// •A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
Fixed::Fixed(const float set_value)
{
	std::cout << "Float constructor called\n";
	value = roundf(set_value * (1 << fbits));
}
// •A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
float Fixed::toFloat( void ) const
{
	return (float)value / (1 << fbits);
}
// •A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.
int Fixed::toInt( void ) const
{
	return roundf(toFloat());
}
// •An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}