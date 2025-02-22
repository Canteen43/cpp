#include "Fixed.hpp"
#include <iostream>
// ◦A static constant integer to store the number of fractional bits. Its value
// will always be the integer literal 8.
const int Fixed::fbits = 8;

// ◦A default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}
// ◦A copy constructor.
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	value = other.getRawBits();
}
// ◦A copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	value = other.getRawBits();
	return *this;
}
// ◦A destructor.
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
// ◦A member function int getRawBits( void ) const;
// that returns the raw value of the fixed-point value.
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return value;
}
// ◦A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw )
{
	value = raw;
}
