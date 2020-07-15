#include "Ellipse.h"

Ellipse::Ellipse(double majorAxis, double minorAxis) :
	Shape((majorAxis * minorAxis * PI) / 4, { majorAxis / 2, minorAxis / 2}),
	majorAxis(majorAxis),
	minorAxis(minorAxis)
{
}

Ellipse::Ellipse(double majorAxis, double minorAxis, Vector2 center) :
	Shape((majorAxis * minorAxis * PI) / 4, center),
	majorAxis(majorAxis),
	minorAxis(minorAxis)
{
}

double Ellipse::MajorAxis() const
{
	return majorAxis;
}

double Ellipse::MinorAxis() const
{
	return minorAxis;
}

std::vector<Shape*> Ellipse::GetAdjecentShapes() const
{
	Vector2 offset = { majorAxis, minorAxis };
	Vector2 adjCenters[4] =
	{
		center + offset * Vector2(1, 0),
		center + offset * Vector2(0, 1),
		center + offset * Vector2(-1, 0),
		center + offset * Vector2(0, -1)
	};

	std::vector<Shape*> adj(4);
	for (int i = 0; i < 4; ++i)
		adj[i] = new Ellipse(majorAxis, minorAxis, adjCenters[i]);

	return adj;
}

bool Ellipse::IsInRectangle(double rectWidth, double rectHeight) const
{
	if (CompareDouble(center.x, majorAxis / 2) > -1 && CompareDouble(center.x, rectWidth - majorAxis / 2) < 1 &&
		CompareDouble(center.y, minorAxis / 2) > -1 && CompareDouble(center.y, rectHeight - minorAxis / 2) < 1)
		return true;

	return false;
}

Shape* Ellipse::clone() const
{
	return new Ellipse(*this);
}
