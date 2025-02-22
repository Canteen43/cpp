#pragma once
#include "Fixed.hpp"
class Point
{
	private:
		// ◦A Fixed const attribute x.
		const Fixed x;
		// ◦A Fixed const attribute y.
		const Fixed y;
		// ◦Anything else useful.
	public:
		// ◦A default constructor that initializes x and y to 0.
		Point();
		// ◦A constructor that takes as parameters two constant floating-point numbers.
		// It initializes x and y with those parameters.
		Point(const float nb1, const float nb2);
		// ◦A copy constructor.
		Point(const Point& other);
		// ◦A copy assignment operator overload.
		Point& operator=(const Point& other);
		// ◦A destructor.
		~Point();
		// ◦Anything else useful.
		const Fixed& getX() const;
		const Fixed& getY() const;
};