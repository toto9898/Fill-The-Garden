#pragma once
#include "Shape.h"

class Triangle :
    public Shape
{
public:
    Triangle(const double sideSize, bool flippedVertically = false);
    Triangle(const double sideSize, const Vector2 center, bool flippedVertically = false);
    virtual ~Triangle();

    double SideSize() const;
    virtual std::vector<Shape*> GetAdjecentShapes() const override;
    virtual bool IsInRectangle(double rectWidth, double rectHeight) const override;

    virtual Shape* clone() const override;

private:
    double sideSize;
    bool flippedVertically;
};
