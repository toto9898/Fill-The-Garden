#include "Shape.h"


Shape::Shape(double area, const Vector2 center) :
	center(center),
	area(area)
{
}

Shape::~Shape()
{
}

Vector2 Shape::Center() const
{
	return center;
}

Shape& Shape::Translate(Vector2 translation)
{
	center += translation;
	return *this;
}

Shape& Shape::Rotate(double angle, bool inDegrees)
{
	center.Rotate(angle, inDegrees);
	return *this;
}

double Shape::Area() const
{
	return area;
}
