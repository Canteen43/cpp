#include <ostream>
#pragma once
class Fixed
{
	private:
		// •An integer to store the fixed-point number value.
		int value;
		// •A static constant integer to store the number of fractional bits. Its value
		// will always be the integer literal 8.	
		static const int fbits;
	public:
		// •A default constructor that initializes the fixed-point number value to 0.
		Fixed();
		// •A copy constructor.
		Fixed(const Fixed& other);
		// •A copy assignment operator overload.
		Fixed& operator=(const Fixed& other);
		// •A destructor.
		~Fixed();
		// •A member function int getRawBits( void ) const;
		// that returns the raw value of the fixed-point value.
		int getRawBits( void ) const;
		// •A member function void setRawBits( int const raw );
		// that sets the raw value of the fixed-point number.
		void setRawBits( int const raw );
		// •A constructor that takes a constant integer as a parameter.
		// It converts it to the corresponding fixed-point value. The fractional bits value is
		// initialized to 8 like in exercise 00.
		Fixed(const int set_value);
		// •A constructor that takes a constant floating-point number as a parameter.
		// It converts it to the corresponding fixed-point value. The fractional bits value is
		// initialized to 8 like in exercise 00.
		Fixed(const float set_value);
		// •A member function float toFloat( void ) const;
		// that converts the fixed-point value to a floating-point value.
		float toFloat( void ) const;
		// •A member function int toInt( void ) const;
		// that converts the fixed-point value to an integer value.
		int toInt( void ) const;
		// •The 6 comparison operators: >, <, >=, <=, == and !=.
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		// •The 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		// •The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
		// post-decrement) operators, that will increase or decrease the fixed-point value from
		// the smallest representable ε such as 1 + ε > 1.
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		// •A static member function min that takes as parameters two references on fixed-point
		// numbers, and returns a reference to the smallest one.
		static Fixed& min(Fixed& first, Fixed& second);
		// •A static member function min that takes as parameters two references to constant
		// fixed-point numbers, and returns a reference to the smallest one.
		static const Fixed& min(const Fixed& first, const Fixed& second);
		// •A static member function max that takes as parameters two references on fixed-point
		// numbers, and returns a reference to the greatest one.
		static Fixed& max(Fixed& first, Fixed& second);
		// •A static member function max that takes as parameters two references to constant
		// fixed-point numbers, and returns a reference to the greatest one.
		static const Fixed& max(const Fixed& first, const Fixed& second);
	};
// •An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream& operator<<(std::ostream& os, const Fixed& obj);