#pragma once
#include <iostream>
#include <vector>
#include "Vector2.h"

const double SQRT3 = 1.732050807568877293;

class Shape
{
public:
	Shape(double area, const Vector2 center = {0,0});
	virtual ~Shape();

	Vector2 Center() const;
	Shape& Translate(Vector2 translation);
	Shape& Rotate(double angle, bool inDegrees = false);
	double Area() const;

	virtual std::vector<Shape*> GetAdjecentShapes() const = 0;
	virtual bool IsInRectangle(double rectWidth, double rectHeight) const = 0;


protected:
	Vector2 center;
	double area;
};

