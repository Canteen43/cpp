#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{

std::cout	<< "Subject requirements:\n"
			"Returns: True if the point is inside the triangle. False otherwise. "
			"Thus, if the point is a vertex or on edge, it will return False.\n\n";

// Printing true and false instead of 0 and 1
std::cout << std::boolalpha;
int test_nbr = 1;
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Point inside of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(1.0, 1.0);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Point just inside of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(1.5, 1.45);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Another point just inside of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(1.49, 1.49);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Point outside of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(5.0, 5.0);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Point on edge of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(1.5, 1.5);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Point on vertex of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(0, 3.0);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}
std::cout << "Test " << test_nbr++ << ": ";
{
	std::cout	<< "Negative point outside of triangle.\n";
	Point a(0, 0);
	Point b(3.0, 0);
	Point c(0, 3.0);
	Point point(-0.5, -0.5);
	std::cout	<< "Result: " << bsp(a, b, c, point) << "\n\n";
}

return 0;
}