#pragma once
#include "Line.h"

class Segment : public virtual Line {
	Point end;
public:
	Segment();
	Segment(const Point&, const Point&);
	Segment(const Segment&);
	virtual ~Segment();
	Segment& operator=(const Segment&);

	virtual double length() const;
	Point midpoint() const;

	virtual bool operator==(const Point&) const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);
};