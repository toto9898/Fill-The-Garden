#include "ShapeFactory.h"

Shape* ShapeFactory::Create(ShapeType type, double size1, double size2)
{
	switch (type)
	{
	case TRIANGLE:
		return new Triangle(size1);
	case HEXAGON:
		return new Hexagon(size1);
	case ELLIPSE:
		return new Ellipse(size1, size2);
	case CIRCLE:
		return new Circle(size1);
	default:
		return nullptr;
	}
}
