#pragma once
#include "Shape.h"

class Hexagon :
    public Shape
{
public:
    Hexagon(const double sideSize);
    Hexagon(const double sideSize, const Vector2 center);

    double SideSize() const;
    std::vector<Shape*> GetAdjecentShapes() const override;
    bool IsInRectangle(double rectWidth, double rectHeight) const;

    Shape* clone() const override;

private:
    double sideSize;
};
