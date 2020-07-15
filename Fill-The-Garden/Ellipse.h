#pragma once
#include "Shape.h"
class Ellipse :
    public Shape
{
public:
    Ellipse(double majorAxis, double minorAxis, Type type = ELLIPSE);
    Ellipse(double majorAxis, double minorAxis, Vector2 center, Type type = ELLIPSE);

    double MajorAxis() const;
    double MinorAxis() const;
    std::vector<Shape*> GetAdjecentShapes() const override;
    bool IsInRectangle(double rectWidth, double rectHeight) const;

    Shape* clone() const override;

private:
    double majorAxis;
    double minorAxis;
};
