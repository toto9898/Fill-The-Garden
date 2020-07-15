#include "Triangle.h"

Triangle::Triangle(const double sideSize, bool flippedVertically) :
	Shape((sideSize* sideSize* SQRT3) / 4, { sideSize / 2, (SQRT3 * sideSize) / 6 }),
	sideSize(sideSize),
	flippedVertically(flippedVertically)
{
}

Triangle::Triangle(const double sideSize, const Vector2 center, bool flippedVertically) :
	Shape((sideSize* sideSize* SQRT3) / 4, center),
	sideSize(sideSize),
	flippedVertically(flippedVertically)
{	
}

double Triangle::SideSize() const
{
	return sideSize;
}

std::vector<Shape*> Triangle::GetAdjecentShapes() const
{
	double height = (SQRT3 * sideSize) / 2;

	double botTriangleYOffset = flippedVertically ? (2 * height) / 3 : -(2 * height) / 3;
	double sideTriangleYOffset = flippedVertically ? -height / 3 : height / 3;

	Vector2 adjCenters[3] =
	{
		{ center.x + sideSize / 2, center.y + sideTriangleYOffset },
		{ center.x - sideSize / 2, center.y + sideTriangleYOffset },
		{ center.x,  center.y + botTriangleYOffset }
	};

	return std::vector<Shape*>
	{
		new Triangle(sideSize, adjCenters[0], !flippedVertically),
		new Triangle(sideSize, adjCenters[1], !flippedVertically),
		new Triangle(sideSize, adjCenters[2], !flippedVertically)
	};
}

bool Triangle::IsInRectangle(double rectWidth, double rectHeight) const
{
	if (CompareDouble(center.x, sideSize / 2) == -1 || 
		CompareDouble(center.x, rectWidth - sideSize / 2) == 1)
		return false;

	double height = (SQRT3 * sideSize) / 2;

	if (!flippedVertically)
	{
		if (CompareDouble(center.y + (height * 2) / 3, rectHeight) == 1 || 
			CompareDouble(center.y - height / 3, 0) == -1)
			return false;
	}
	else
	{
		if (CompareDouble(center.y + height / 3, rectHeight) == 1 || 
			CompareDouble(center.y - (height * 2) / 3, 0) == -1)
			return false;
	}

	return true;
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

