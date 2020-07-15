#pragma once
#include <vector>
#include "Vector2.h"

const double SQRT3 = 1.732050807568877293;


class Shape
{
public:
	enum Type
	{
		INVALID = -1,
		TRIANGLE,
		HEXAGON,
		ELLIPSE,
		CIRCLE,

		NUM_OF_TYPES
	};

	static const char* const  NAMES[NUM_OF_TYPES];

public:
	static Shape* Create(Type type, double size1, double size2 = 1);

public:
	Shape(double area, Type type, const Vector2 center = {0,0});
	virtual ~Shape();

	Vector2 Center() const;
	Shape& Translate(Vector2 translation);
	Shape& Rotate(double angle, bool inDegrees = false);
	double Area() const;
	Type GetType() const;

	virtual std::vector<Shape*> GetAdjecentShapes() const = 0;
	virtual bool IsInRectangle(double rectWidth, double rectHeight) const = 0;

	virtual Shape* clone() const = 0;

protected:
	Vector2 center;
	double area;
	Type type;
};

