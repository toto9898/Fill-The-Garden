#include "Hexagon.h"

Hexagon::Hexagon(const double sideSize) :
	Shape((3 * SQRT3 * sideSize * sideSize) / 2, HEXAGON, { (sideSize * SQRT3) / 2, sideSize }),
	sideSize(sideSize)
{
}

Hexagon::Hexagon(const double sideSize, const Vector2 center) :
	Shape((3 * SQRT3 * sideSize * sideSize) / 2, HEXAGON, center),
	sideSize(sideSize)
{
}

double Hexagon::SideSize() const
{
	return sideSize;
}

std::vector<Shape*> Hexagon::GetAdjecentShapes() const
{

	double offsetRight = sideSize * SQRT3;
	double offsetUp = sideSize + sideSize / 2;

	Vector2 adjCenters[6] =
	{
		{ center.x + offsetRight, center.y },
		{ center.x - offsetRight, center.y },
		{ center.x + offsetRight / 2, center.y + offsetUp},
		{ center.x - offsetRight / 2, center.y + offsetUp},
		{ center.x + offsetRight / 2, center.y - offsetUp},
		{ center.x - offsetRight / 2, center.y - offsetUp},
	};

	std::vector<Shape*> adj(6);
	for (int i = 0; i < 6; ++i)
		adj[i] = new Hexagon(sideSize, adjCenters[i]);

	return adj;
}

bool Hexagon::IsInRectangle(double rectWidth, double rectHeight) const
{
	if (CompareDouble(center.x, (SQRT3 * sideSize) / 2) > -1 && CompareDouble(center.x, rectWidth - (SQRT3 * sideSize) / 2) < 1 &&
		CompareDouble(center.y, sideSize) > -1 && CompareDouble(center.y, rectHeight - sideSize) < 1)
		return true;

	return false;
}

Shape* Hexagon::clone() const
{
	return new Hexagon(*this);
}
