#pragma once
#include "Ellipse.h"

class Circle :
    public Ellipse
{
public:
    Circle(double radius);
    Circle(double radius, Vector2 center);

    double Radius();

    Shape* clone() const override;

private:
    double radius;
};

