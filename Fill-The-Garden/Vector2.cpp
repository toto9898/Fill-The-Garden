#include <cmath>
#include <exception>
#include "Vector2.h"


Vector2::Vector2(const double x, const double y) :
	x(x),
	y(y)
{
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	Vector2 cpy(*this);
	return Vector2(cpy += rhs);
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	Vector2 cpy(*this);
	return Vector2(cpy -= rhs);
}

Vector2& Vector2::operator*=(const Vector2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

Vector2 Vector2::operator*(const Vector2& rhs) const
{
	Vector2 cpy(*this);
	return Vector2(cpy *= rhs);
}

Vector2& Vector2::operator/=(const Vector2& rhs)
{
	if (rhs.x == 0 || rhs.y == 0)
		throw std::exception("Dividing by zero");
	x /= rhs.x;
	y /= rhs.y;
	return *this;
}

Vector2 Vector2::operator/(const Vector2& rhs) const
{
	Vector2 cpy(*this);
	return Vector2(cpy /= rhs);
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool Vector2::operator<(const Vector2& rhs) const
{
	if (CompareDouble(x, rhs.x) == -1)
		return true;
	if (CompareDouble(x, rhs.x) == 0 &&
		CompareDouble(y, rhs.y) == -1)
		return true;
	return false;
}

bool Vector2::operator<=(const Vector2& rhs) const
{
	return *this < rhs || *this == rhs;
}

bool Vector2::operator>(const Vector2& rhs) const
{
	return !(*this <= rhs);
}

bool Vector2::operator>=(const Vector2& rhs) const
{
	return !(*this < rhs);
}

bool Vector2::operator==(const Vector2& rhs) const
{
	return CompareDouble(x, rhs.x) == 0 && CompareDouble(y, rhs.y) == 0;
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return !(*this == rhs);
}

double Vector2::DotProduct(const Vector2& v2) const
{
	 return x * v2.x + y * v2.y;
}

Vector2& Vector2::Rotate(double angle, Vector2 origin, bool inDegrees)
{
	if (inDegrees)
		angle = (angle * PI) / 180; // convert to radians

	double s = sin(angle);
	double c = cos(angle);

	Vector2 newCenter;
	*this -= origin;

	newCenter.x = DotProduct({ c, -s });
	newCenter.y = DotProduct({ s, c });

	newCenter += origin;
	
	// rounding 2 places after the point
	newCenter *= {100, 100};
	newCenter = { round(newCenter.x), round(newCenter.y) };
	newCenter /= {100, 100};

	*this = newCenter;

	return *this;
}

Vector2& Vector2::Rotate(double angle, bool inDegrees)
{
	return Rotate(angle, { 0, 0 }, inDegrees);
}

int CompareDouble(double x1, double x2)
{
	if (abs(x1 - x2) <= EPS_PRECISION) return 0;
	if (x1 - x2 > EPS_PRECISION) return 1;
	if (x2 - x1 > EPS_PRECISION) return -1;
}
