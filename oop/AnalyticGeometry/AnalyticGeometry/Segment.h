#pragma once
#include "Line.h"

class Segment : public virtual Line {
	Point end;
public:
	Segment(const Point&, const Point&);

	virtual double length() const;
	Point midpoint() const;

	virtual bool operator==(const Point&) const;
};