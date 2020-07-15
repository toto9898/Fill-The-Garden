#pragma once
#include "Triangle.h"
#include "Hexagon.h"
#include "Ellipse.h"
#include "Circle.h"

enum ShapeType
{
	INVALID = -1,
	TRIANGLE,
	HEXAGON,
	ELLIPSE,
	CIRCLE,

	NUM_OF_TYPES
};

const char* const  SHAPE_NAMES[NUM_OF_TYPES] = { "triangle", "hexagon", "ellipse", "circle" };

class ShapeFactory
{
public:
	Shape* Create(ShapeType type, double size1, double size2 = 1);
};

