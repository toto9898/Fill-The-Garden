#pragma once
const double PI = 3.141592653589793238;
const double EPS_PRECISION = 0.0001;

int CompareDouble(double x1, double x2);

class Vector2
{
public:
	Vector2(const double x = 0, const double y = 0);

	Vector2& operator+=(const Vector2& rhs);
	Vector2 operator+(const Vector2& rhs) const;
	Vector2& operator-=(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs) const;
	Vector2& operator*=(const Vector2& rhs);
	Vector2 operator*(const Vector2& rhs) const;
	Vector2& operator/=(const Vector2& rhs);
	Vector2 operator/(const Vector2& rhs) const;
	Vector2& operator=(const Vector2& rhs);
	bool operator<(const Vector2& rhs) const;
	bool operator<=(const Vector2& rhs) const;
	bool operator>(const Vector2& rhs) const;
	bool operator>=(const Vector2& rhs) const;
	bool operator==(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs) const;

	double DotProduct(const Vector2& v2) const;
	Vector2& Rotate(double angle, Vector2 origin, bool inDegrees = false);
	Vector2& Rotate(double angle, bool inDegrees = false);

	double x, y;
};

