#pragma once
#include "Vector.h"

class Line : public virtual Vector {
	Vector slope;
	friend bool operator+(const Point&, const Line&);
public:
	Line(const Point&, const Vector&);
	Line(const Point&, const Point&);

	virtual Vector direction() const;
	Vector normal() const;
	virtual double angle(const Line&) const;
	double distance(const Line&) const;
	bool operator||(const Line&) const;
	virtual bool operator==(const Line&) const;
	bool operator&&(const Line&) const;
	bool operator!=(const Line&) const;
	bool operator|(const Line&) const;
};

bool operator+(const Point&, const Line&);
bool operator+(const Line&, const Point&);