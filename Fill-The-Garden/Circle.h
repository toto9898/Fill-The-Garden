#pragma once
#include "Ellipse.h"

class Circle :
    public Ellipse
{
public:
    Circle(double radius);
    Circle(double radius, Vector2 center);

    double Radius();

private:
    double radius;
};

