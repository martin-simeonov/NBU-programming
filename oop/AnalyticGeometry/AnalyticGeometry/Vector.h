#pragma once
#include "Point.h"

class Vector : public virtual Point {
	friend Vector operator*(const Vector&, double r);
public:
	Vector(double = 0.0, double = 0.0, double = 0.0);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	virtual ~Vector();
	Vector& operator=(const Vector&);

	virtual double length() const;
	virtual Vector direction() const;
	Vector project(const Vector&) const;
	Vector project(const Vector&, const Vector&) const;
	bool isZero() const;
	bool parallel(const Vector&) const;
	bool perpendicular(const Vector&) const;
	virtual double angle(const Vector&) const;

	Vector operator+(const Vector&) const;
	Vector operator-(const Vector&) const;
	double operator*(const Vector&) const;
	Vector operator^(const Vector&) const;
	double operator()(const Vector&, const Vector&) const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);
};

Vector operator*(const Vector&, double r);
Vector operator*(double r, const Vector&);