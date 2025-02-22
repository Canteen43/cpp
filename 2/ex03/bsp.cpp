#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

float area(const Point first, const Point second, const Point third) {
	float x1 = first.getX().toFloat();
	float y1 = first.getY().toFloat();
	float x2 = second.getX().toFloat();
	float y2 = second.getY().toFloat();
	float x3 = third.getX().toFloat();
	float y3 = third.getY().toFloat();

	float result = 0.5f * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	if (result < 0)
		result *= -1;
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float pab = area(point, a, b);
	float pac = area(point, a, c);
	float pbc = area(point, b, c);
	if (!pab || !pac || !pbc)
		return false;
	if (pab + pac + pbc != area(a, b, c))
		return false;	
	return true;
}
/*Unfortunately, doing the calculations with fixed point numbers resulted in
inferior accuracy. (Wrong negative for P(1.5, 1.45))*/
// Fixed area(const Point first, const Point second, const Point third) {
// 	Fixed x1 = first.getX();
// 	Fixed y1 = first.getY();
// 	Fixed x2 = second.getX();
// 	Fixed y2 = second.getY();
// 	Fixed x3 = third.getX();
// 	Fixed y3 = third.getY();

// 	Fixed result = Fixed(0.5f) * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
// 	if (result < 0)
// 		result = result * -1;
// 	return result;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed pab = area(point, a, b);
// 	Fixed pac = area(point, a, c);
// 	Fixed pbc = area(point, b, c);
// 	if (pab == 0 || pac == 0 || pbc == 0)
// 	return false;
// 	Fixed abc = area(a, b, c);
// 	if (pab + pac + pbc != abc)
// 		return false;	
// 	return true;
// }