#pragma once
#include "Shape.h"

class Hexagon :
    public Shape
{
public:
    Hexagon(const double sideSize);
    Hexagon(const double sideSize, const Vector2 center);
    virtual ~Hexagon();

    double SideSize() const;
    virtual std::vector<Shape*> GetAdjecentShapes() const override;
    virtual bool IsInRectangle(double rectWidth, double rectHeight) const override;

    virtual Shape* clone() const override;

private:
    double sideSize;
};
