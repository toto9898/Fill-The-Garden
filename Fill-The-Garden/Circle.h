#pragma once
#include "Ellipse.h"

class Circle :
    public Ellipse
{
public:
    Circle(double radius);
    Circle(double radius, Vector2 center);
    virtual ~Circle();

    double Radius();

    virtual Shape* clone() const override;

private:
    double radius;
};

