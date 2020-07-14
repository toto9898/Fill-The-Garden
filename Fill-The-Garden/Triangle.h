#pragma once
#include "Shape.h"

class Triangle :
    public Shape
{
public:
    Triangle(const double sideSize, bool flippedVertically = false);
    Triangle(const double sideSize, const Vector2 center, bool flippedVertically = false);

    double SideSize() const;
    std::vector<Shape*> GetAdjecentShapes() const override;
    bool IsInRectangle(double rectWidth, double rectHeight) const;

private:
    double sideSize;
    bool flippedVertically;
};
