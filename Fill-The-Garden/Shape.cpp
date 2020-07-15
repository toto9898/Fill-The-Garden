#include "Shape.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Ellipse.h"
#include "Circle.h"

const char* const Shape::NAMES[NUM_OF_TYPES] = { "triangle", "hexagon", "ellipse", "circle" };

Shape* Shape::Create(Type type, double size1, double size2)
{
	switch (type)
	{
	case Shape::TRIANGLE:
		return new Triangle(size1);
	case Shape::HEXAGON:
		return new Hexagon(size1);
	case Shape::ELLIPSE:
		return new Ellipse(size1, size2);
	case Shape::CIRCLE:
		return new Circle(size1);
	default:
		return nullptr;
	}
}

Shape::Shape(double area, Type type, const Vector2 center) :
	center(center),
	area(area),
	type(type)
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

Shape::Type Shape::GetType() const
{
	return type;
}
