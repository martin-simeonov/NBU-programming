#pragma once
#include "Element.h"

class Point : public virtual Element {
protected:
	double x, y, z;
public:
	Point(double = 0.0, double = 0.0, double = 0.0);
	Point(const Point&);
	virtual ~Point();
	Point& operator=(const Point&);

	virtual double getX() const;
	virtual double getY() const;
	virtual double getZ() const;

	virtual bool operator==(const Point&) const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);

	virtual void printMethods() const;
	virtual void executeMethod(int, std::istream&, std::ostream&) const;
};