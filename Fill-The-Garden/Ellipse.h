#pragma once
#include "Shape.h"
class Ellipse :
    public Shape
{
public:
    Ellipse(double majorAxis, double minorAxis);
    Ellipse(double majorAxis, double minorAxis, Vector2 center);
    virtual ~Ellipse();

    double MajorAxis() const;
    double MinorAxis() const;
    virtual std::vector<Shape*> GetAdjecentShapes() const override;
    virtual bool IsInRectangle(double rectWidth, double rectHeight) const override;

    virtual Shape* clone() const override;

private:
    double majorAxis;
    double minorAxis;
};
