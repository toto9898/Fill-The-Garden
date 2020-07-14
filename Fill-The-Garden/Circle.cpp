#include "Circle.h"

Circle::Circle(double radius) :
	Ellipse(radius * 2, radius * 2, { radius, radius }),
	radius(radius)
{
}

Circle::Circle(double radius, Vector2 center) :
	Ellipse(radius * 2, radius * 2, center),
	radius(radius)
{
}

double Circle::Radius()
{
	return radius;
}
