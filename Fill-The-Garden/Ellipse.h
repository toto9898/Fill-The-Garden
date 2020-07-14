#pragma once
#include "Shape.h"
class Ellipse :
    public Shape
{
public:
    Ellipse(double majorAxis, double minorAxis);
    Ellipse(double majorAxis, double minorAxis, Vector2 center);

    double MajorAxis() const;
    double MinorAxis() const;
    std::vector<Shape*> GetAdjecentShapes() const override;
    bool IsInRectangle(double rectWidth, double rectHeight) const;

private:
    double majorAxis;
    double minorAxis;
};
