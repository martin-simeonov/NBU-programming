#pragma once
#include "Vector.h"

class Line : public virtual Vector {
	friend bool operator+(const Point&, const Line&);
protected:
	Vector slope;
public:
	Line();
	Line(const Point&, const Vector&);
	Line(const Point&, const Point&);
	Line(const Line&);
	virtual ~Line();
	Line& operator=(const Line&);

	virtual Vector direction() const;
	Vector normal() const;
	virtual double angle(const Line&) const;
	double distance(const Line&) const;
	bool operator||(const Line&) const;
	virtual bool operator==(const Line&) const;
	bool operator&&(const Line&) const;
	bool operator!=(const Line&) const;
	bool operator|(const Line&) const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);
};

bool operator+(const Point&, const Line&);
bool operator+(const Line&, const Point&);