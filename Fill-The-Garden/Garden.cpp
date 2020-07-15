#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include "Garden.h"

Garden::Garden(double width, double height) :
	width(width),
	height(height),
	type(INVALID)
{
}

Garden::Garden(const Garden& rhs)
{
	Copy(rhs);
}

Garden& Garden::operator=(const Garden& rhs)
{
	if (this != &rhs)
	{
		Free();
		Copy(rhs);
	}
	return *this;
}

Garden::~Garden()
{
	Free();
}

void Garden::Fill(ShapeType type, double size1, double size2)
{
	Free();
	shapes.clear();

	shapes.push_back(factory.Create(type, size1, size2));
	if (!shapes[0])
		return;

	if (shapes[0]->IsInRectangle(width, height) == false)
	{
		delete shapes[0];
		shapes.pop_back();
		return;
	}

	std::set<Vector2> added;
	std::queue<Shape*> q;

	q.push(shapes[0]);
	added.insert(shapes[0]->Center());

	while (!q.empty())
	{
		Shape* shape = q.front();
		q.pop();

		auto neighbours = shape->GetAdjecentShapes();
		for (Shape*& neighbour : neighbours)
			if (!added.count(neighbour->Center()))
			{
				if (neighbour->IsInRectangle(width, height))
				{
					added.insert(neighbour->Center());
					shapes.push_back(neighbour);
					q.push(neighbour);
				}
				else
				{
					delete neighbour;
					neighbour = nullptr;
				}
			}
	}

	this->type = type;
}

void Garden::Rotate(double angle, bool inDegrees)
{
	for (Shape* shape : shapes)
		shape->Rotate(angle, inDegrees);
}

ShapeType Garden::PlantsCrownType() const
{
	return type;
}

void Garden::PrintPlantsCount() const
{
	std::cout << "Number of plants: " << shapes.size() << "\n";
}

void Garden::PrintPlantsCenters() const
{
	std::cout << "Coordinates of the shape's centers: \n";

	for (Shape* shape : shapes)
		std::cout << "\t(" << shape->Center().x << ", " << shape->Center().y << ")\n";
}

void Garden::PrintAreaCovered() const
{
	double overallArea = 0;
	if (shapes.size() > 0)
		overallArea = shapes.size() * shapes[0]->Area();

	double areaCovered = (100 * overallArea) / (width * height);
	std::cout << "Overall area covered: ";
	std::cout << std::fixed << std::setprecision(2) << areaCovered << "%\n";
}

void Garden::Copy(const Garden& from)
{
	width = from.width;
	height = from.height;

	size_t size = from.shapes.size();
	shapes.resize(size);
	for (size_t i = 0; i < size; ++i)
		shapes[i] = from.shapes[i]->clone();
}

void Garden::Free()
{
	width = 1;
	height = 1;

	for (Shape*& shape : shapes)
	{
		delete shape;
		shape = nullptr;
	}

	shapes.clear();
}
