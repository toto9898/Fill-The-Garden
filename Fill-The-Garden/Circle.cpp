#include "Circle.h"

Circle::Circle(double radius) :
	Ellipse(radius * 2, radius * 2, { radius, radius }, CIRCLE),
	radius(radius)
{
}

Circle::Circle(double radius, Vector2 center) :
	Ellipse(radius * 2, radius * 2, center, CIRCLE),
	radius(radius)
{
}

double Circle::Radius()
{
	return radius;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}
