#pragma once
#include <vector>
#include "Shape.h"
#include "ShapeFactory.h"


class Garden
{
public:
	Garden(double width, double height);
	Garden(const Garden& rhs);
	Garden& operator=(const Garden& rhs);
	~Garden();

	void Fill(ShapeType type, double size1, double size2 = 1);
	void Rotate(double angle, bool inDegrees = false);

	ShapeType PlantsCrownType() const;
	void PrintPlantsCount() const;
	void PrintPlantsCenters() const;
	void PrintAreaCovered() const;

private:
	void Copy(const Garden& from);
	void Free();
private:
	double width;
	double height;
	ShapeType type;
	std::vector<Shape*> shapes;

	ShapeFactory factory;
};

