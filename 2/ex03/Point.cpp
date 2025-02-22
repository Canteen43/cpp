#include "Point.hpp"
// ◦A default constructor that initializes x and y to 0.
Point::Point() : x(0), y(0)
{}
// ◦A constructor that takes as parameters two constant floating-point numbers.
// It initializes x and y with those parameters.
Point::Point(const float nb1, const float nb2) : x(nb1), y(nb2)
{}
// ◦A copy constructor.
Point::Point(const Point& other) : x(other.x), y(other.y)
{}
// ◦A copy assignment operator overload.
// Point& Point::operator=(const Point& other)
// {
// 	x.setRawBits(other.x.getRawBits());
// 	y.setRawBits(other.y.getRawBits());
// }
// ◦A destructor.
Point::~Point()
{}
// ◦Anything else useful.
const Fixed& Point::getX() const
{
	return x;
}
const Fixed& Point::getY() const
{
	return y;
}